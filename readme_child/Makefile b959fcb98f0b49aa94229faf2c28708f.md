# Makefile

by Likilee’s github

# BeforeStart/Makefile

- **make 란?**
    - `make`는 소프트웨어 개발을 위해 유닉스 계열 운영 체제에서 주로 사용되는 프로그램 빌드 도구이다. `여러 파일들끼리의 의존성`과 각 파일에 필요한 명령을 정의함으로써 프로그램을 컴파일할 수 있으며 최종 프로그램을 만들 수 있는 과정을 서술할 수 있는 표준적인 문법을 가지고 있다.
- **Makefile 이란?**
    - Makefile은 프로그램을 빌드하기 위해 `make`의 문법에 따라 작성하는 문서

---

# BeforeStart/Compiler

> 실습교재 '소스코드는 어떻게 실행파일이 되는가?' 파트를 학습하고 '컴파일러 실습' 파트에 따라 실습을 진행합니다.
> 
- **소스코드는 어떻게 실행파일이 되는가?**

먼저 프로그램을 빌드하기 위해 컴파일러가 하는 일을 알아봅시다.

hello.c 소스파일을 -> hello.exe 실행파일로 빌드하기 위해 우리는 쉘에 `gcc hello.c` 명령을 치면 된다는 것을 알고있습니다. 하지만 실제 이 단순한 명령이 실행파일을 빌드하는데에는 총 네 가지 단계가 존재합니다.

`전처리 단계 -> 컴파일 단계 -> 어셈블 단계 -> 링크단계`

## 1. 전처리 단계

gcc에서 가장 먼저 작동하는 단계로 전처리기가 소스 파일 내의 전처리기 지시자를 처리합니다. 전처리기 지시자는 `#으로 시작하고 세미콜론 없이 개행문자로 종료되는 라인`입니다. 이 단계를 거치면 소스파일 **hello.c**로부터 확장 소스 파일 **hello.i**를 생성합니다.

전처리기 지사자 예시) #include: 지정된 특정 파일의 내용을 해당 지시자가 있는 위치에 삽입 #define: 매크로 함수 및 상수 정의에 사용, 코드 내의 해당 상수를 프로그래머가 정의한 문자열로 대체

## 2. 컴파일 단계

일반적으로 우리가 사용하는 컴파일이라는 용어는 넓은 의미로 이 네가지 단계를 모두 포함하는 작업을 뜻하지만 여기서의 컴파일 단계는 좁은 의미로서 컴파일러가 전처리된 파일 **hello.i**로부터 어셈블리어로 된 파일 **hello.s**를 생성합니다.

## 3. 어셈블 단계

어셈블리어 파일 **hello.s**를 기계어로 된 오브젝트 파일 **hello.o**로 변환합니다.

## 4. 링크 단계

오브젝트 파일은 사용한 라이브러리 함수 (write, printf 등)에 해당하는 코드가 없기 때문에 실행될 수 없습니다. 또한 여러 파일로 이루어진 프로그램의 경우에도 파일간의 연결이 이뤄지지 않아 실행될 수 없습니다. 링크 단계는 라이브러리 함수와 오브젝트 파일들을 연결해서 실행 가능한 파일을 생성합니다. **hello.o -> hello.exe**

`gcc hello.c`로 빌드하게 되면 위 네 단계를 거쳐 실행파일이 생성되지만 각 단계 파일들은 임시파일로 생성되고 사라지기 때문에 우리는 몰랐던 것입니다. gcc에는 옵션을 통해 이러한 단계를 구분하여 컴파일이 가능합니다. 실습을 통해 눈으로 확인해 봅시다!

### 컴파일러 실습

실습 자료의 `BeforeStart/Compiler` 디렉토리에서 순서대로 아래 명령을 입력하며 생성되는 파일을 확인해보세요.

```bash
//STEP1. 전처리 단계 [ *.c -> *.i ]
gcc -E main.c -o main.i
gcc -E func.c -o func.i

//STEP2. ~ 컴파일 단계 [ *.c -> (*.i) -> *.s ]
gcc -S main.c func.c

//STEP3. ~ 어셈블 단계 [ *.c -> (*.i) -> (*.s) -> *.o ]
gcc -c main.c func.c

//STEP4. ~ 링크 단계 [ *.c -> (*.i) -> (*.s) -> (*.o) -> executable ]
gcc -o main main.c func.c
```

---

# BeforeStart/Archiver

> 실습 교재 '아카이버 실습' 파트에 따라 실습을 진행합니다.
> 

### 아카이버 실습

실습 자료의 'BeforeStart/Archiver' 디렉토리에서 아래 명령을 입력하여 생성되는 파일을 확인해 보세요 (man ar 참고)

```bash
//STEP1. 오브젝트 파일 생성 [ *.c -> *.o ]
gcc -c first.c second.c third.c

//STEP2. 오브젝트 파일로 정적 라이브러리 파일 생성 [ *.o -> *.a ]
ar rcs libft.a first.o second.o third.o

// ar 유틸리티
// 사용법 : ar [옵션들] [라이브러리 이름] [오브젝트 파일들]
// 주요 옵션 
// -r : 새로운 오브젝트 파일이면 아카이브에 추가, 기존 파일이면 치환함.
// -c : 라이브러리 파일이 존재하지 않아도 경고 메시지를 출력하지 않음.
// -s : 아카이브 인덱스를 생성 
//			→ 아카이브 인덱스를 생성하지 않으면 링크 속도가 느려지고, 시스템 환경에 따라서는 에러가 발생.
```

---

# 3. Level 0~9

> Level 0 부터 9 까지 10단계로 구성되어 있으며, 실습을 마치면, 메이크파일을 이용해서 subject.ko.txt에 적힌 문제를 Quiz 디렉토리에 제공된 소스코드를 대상으로 해결하는 방식으로 학습합니다.
> 

Makefile의 가장 기본적인 구조는 목표 파일(Target)과 의존성(Dependency) 그리고 의존성이 만족될 때 실행되는 레시피(Recipe)로 구성된 '규칙(Rule)'입니다.

```bash
# 목표 파일과 의존성 사이에는 ':'이 와야합니다.
# 레시피는 반드시 수평탭을 통한 들여쓰기를 해야합니다. (space 안됨)
목표 파일 : 의존성
	레시피
	
# 예시
target : target.c
	gcc target.c
```

- make는 인자없이 실행했을 때, Makefile에서 가장 먼저 나오는 (가장 위에 있는) Rule을 실행합니다.
- '리링크'를 방지하는게 무엇인가요?
    - '리링크'에서의 링크는 컴파일 단계 중 링크 단계의 동작을 말합니다.
    - Makefile은 목표 파일과 의존성의 **Time Stamp(최근 수정시간)을 비교**해서 의존성이 목표파일보다 더 최신인 경우 해당 레시피를 실행합니다

### **Level 0**

**Quiz**

```bash
학습 목표 : Makefile의 기본 구조를 이해한다.
---------
< 문제 >
main.c 파일을 main.o 파일로 만든 뒤, main 이라는 이름의 실행파일을 만드는 Makefile을 작성하시오

< 제한 사항 >
- 두 개의 Rule을 작성하시오.
- 변수를 사용하지 마시오.
- 'make' 실행 시 목표를 달성해야합니다.
- 리링크되지 않아야합니다.
```

**Solve**

```bash
main : main.o
	gcc main.o -o main
	
main.o : main.c
	gcc -c main.c -o main.o
```

### **Level 1**

**Quiz**

```bash
학습 목표
- Makefile로 정적라이브러리를 생성할 수 있다.
- 기본 규칙과 기본 변수가 존재함을 안다.
---------
< 문제 >
.c 파일들을 .o 파일로 컴파일한 뒤, ft라는 이름의 정적라이브러리 파일(libft.a)로 만드시오.

< 제한 사항 >
- 변수를 사용하지 마시오.
- ar 유틸리티를 사용하여 archive 하시오.
- 2줄 이내로 작성하시오
- 한가지 Rule만을 사용하여 작성하시오.
- 리링크되지 않아야 합니다.
```

**Solve**

```bash
libft.a : first.o second.o third.o
	ar rcs libft.a first.o second.o third.o
```

### **Level 2**

**Quiz**

```bash
학습 목표 : 변수(Variables)를 사용할 수 있다.
---------
< 문제 >
.c 파일들을 .o 파일로 컴파일한 뒤, ft라는 이름의 정적라이브러리 파일(libft.a)로 만드시오.

< 제한 사항 >
- Rule을 변수만으로 작성하시오.
- 적절한 변수를 할당하시오.
- ar 유틸리티를 사용하여 archive 하시오.
- 리링크되지 않아야 합니다.
```

**Solve**

```bash
NAME := libft.a
OBJS := first.o second.o third.o
AR := ar
ARFLAGS := rcs

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
```

### **Level 3**

**Quiz**

```bash
학습 목표 : 자동 변수(Automatic variables)를 사용할 수 있다.
---------
< 문제 >
.c 파일들을 .o 파일로 컴파일한 뒤, ft라는 이름의 정적라이브러리 파일(libft.a)로 만드시오.

< 제한 사항 >
 - Rule의 Recipe 작성 시 Target과 Dependency를 적절한 자동 변수(Automatic Variables)를 사용하여 작성하세요.
 - Rule을 변수만으로 작성하시오.
 - 적절한 변수를 할당하시오.
 - ar 유틸리티를 사용하여 archive 하시오.
 - 리링크되지 않아야 합니다.
```

**Solve**

```bash
NAME := libft.a
OBJS := first.o second.o third.o
AR := ar
ARFLAGS := rcs

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?
```

### **Level 4**

**Quiz**

```bash
학습 목표 : 패턴 Rule을 사용할 수 있다.
---------
< 문제 >
.c 파일들을 .o 파일로 컴파일한 뒤, ft라는 이름의 정적라이브러리 파일(libft.a)로 만드시오.

< 제한 사항 >
 - 패턴 Rule을 사용하여 오브젝트 파일 생성 규칙을 정의하시오
 - Rule의 Recipe 작성 시 Target과 Dependency를 적절한 자동 변수(Automatic Variables)를 사용하여 작성하세요.
 - Rule을 변수만으로 작성하시오.
 - 적절한 변수를 할당하시오.
 - ar 유틸리티를 사용하여 archive 하시오.
 - 리링크되지 않아야 합니다.
```

**Solve**

```bash
NAME := libft.a
OBJS := first.o second.o third.o
AR := ar
ARFLAGS := rcs
CC := gcc
CFLAGS := -c

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) $<
```

### **Level 5**

**Quiz**

```bash
학습 목표
 - 함수를 사용할 수 있다.
 - 함수를 사용하여 변수를 치환할 수 있다.
---------
< 문제 >
.c 파일들을 .o 파일로 컴파일한 뒤, ft라는 이름의 정적라이브러리 파일(libft.a)로 만드시오.

< 제한 사항 >
 - .c 파일들을 할당한 변수를 함수로 치환하여 .o 파일을 할당할 변수로 정의하시오.
 - 패턴 Rule을 사용하여 오브젝트 파일 생성 규칙을 정의하시오
 - Rule의 Recipe 작성 시 Target과 Dependency를 적절한 자동 변수(Automatic Variables)를 사용하여 작성하세요.
 - Rule을 변수만으로 작성하시오.
 - 적절한 변수를 할당하시오.
 - ar 유틸리티를 사용하여 archive 하시오.
 - 리링크되지 않아야 합니다.
```

**Solve**

```bash
NAME := libft.a
SRCS := first.c second.c third.c
OBJS := $(SRCS:.c=.o)
AR := ar
ARFLAGS := rcs
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) $<
```

### **Level 6**

**Quiz**

```bash
학습 목표
 - Phony target 을 사용할 수 있다.
---------
< 문제 >
 -.c 파일들을 .o 파일로 컴파일한 뒤, ft라는 이름의 정적라이브러리 파일(libft.a)로 만드시오.
 - 'make all' 실행 시 'libft.a' 파일이 생성되도록 작성하시오.
 - 'make' 실행 시 'make all'이 실행되게 하시오.
 - 'make clean' 명령 실행 시 오브젝트파일이 삭제될 수 있게하시오.
 - 'make fclean' 명령 실행 시 'libft.a' 파일이 삭제되도록하시오.
 - 'make re' 명령 실행 시 'make fclean' 'make all' 을 연속으로 실행한 것과 같은 결과가 되게 하시오.

< 제한 사항 >
 - .c 파일들을 할당한 변수를 함수로 치환하여 .o 파일을 할당할 변수로 정의하시오.
 - 패턴 Rule을 사용하여 오브젝트 파일 생성 규칙을 정의하시오
 - Rule의 Recipe 작성 시 Target과 Dependency를 적절한 자동 변수(Automatic Variables)를 사용하여 작성하세요.
 - Rule을 변수만으로 작성하시오.
 - 적절한 변수를 할당하시오.
 - ar 유틸리티를 사용하여 archive 하시오.
 - 리링크되지 않아야 합니다.
```

**Solve**

```bash
NAME := libft.a
SRCS := first.c second.c third.c
OBJS := $(SRCS:.c=.o)
AR := ar
ARFLAGS := rcs
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c

.PHONY : all clean fclean re

all: $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) $<
```

### **Level 7**

**Quiz**

```bash
학습 목표
 - 좀 더 복잡한 형태의 메이크파일을 만들 수 있다.
---------
< 문제 >
 -.c 파일들을 .o 파일로 컴파일한 뒤, ft라는 이름의 정적라이브러리 파일(libft.a)로 만드시오.
 - main.c를 main.o 파일로 컴파일한 뒤, libft.a 파일과 링킹하여 실행파일 main을 만드시오.

< 제한 사항 >
 - .c 파일들을 할당한 변수를 함수로 치환하여 .o 파일을 할당할 변수로 정의하시오.
 - 패턴 Rule을 사용하여 오브젝트 파일 생성 규칙을 정의하시오
 - Rule의 Recipe 작성 시 Target과 Dependency를 적절한 자동 변수(Automatic Variables)를 사용하여 작성하세요.
 - Rule을 변수만으로 작성하시오.
 - 적절한 변수를 할당하시오.
 - ar 유틸리티를 사용하여 archive 하시오.
 - 리링크되지 않아야 합니다.
```

**Solve**

```bash
NAME := main
SRCS := main.c
OBJS := $(SRCS:.c=.o)

LIBFT := libft.a
LIB_SRCS := first.c second.c third.c
LIB_OBJS := $(LIB_SRCS:.c=.o)

AR := ar
ARFLAGS := rcs
CC := gcc
CFLAGS := -Wall -Wextra -Werror

.PHONY : all clean fclean
all : $(NAME)
clean :
	rm -f *.o
fclean :
	rm -f $(LIBFT) $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT) : $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<
```

### **Level 8**

**Quiz**

```bash
학습 목표
 - 디렉토리에 정리된 소스코드로 메이크파일을 만들 수 있다.
---------
< 문제 >
 - ./src/*.c 파일들을 ./obj/*.o 파일로 컴파일 한 뒤 ./main을 생성하시오.
 - 'make run'을 실행하면 ./main 을 실행하도록 작성하시오.

< 제한 사항 >
 - .c 파일들을 할당한 변수를 함수로 치환하여 .o 파일을 할당할 변수로 정의하시오.
 - 패턴 Rule을 사용하여 오브젝트 파일 생성 규칙을 정의하시오
 - Rule의 Recipe 작성 시 Target과 Dependency를 적절한 자동 변수(Automatic Variables)를 사용하여 작성하세요.
 - Rule을 변수만으로 작성하시오.
 - 적절한 변수를 할당하시오.
 - 리링크되지 않아야 합니다.
```

**Solve**

```bash
SRC_DIR = ./src/
OBJ_DIR = ./obj/
HEADER_DIR = ./include/

NAME = main
SRC_NAME = main.c first.c second.c third.c
SRCS = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re run
all : $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
run : all
	./$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)
```

### **Level 9**

**Quiz**

```bash
학습 목표
 - 다른 make 파일을 호출할 수 있다.
---------
< 문제 >
 - 'make all' ./src/*.c 파일들을 ./obj/*.o 파일로 컴파일 한 뒤 ./lib/libft.a 와 링킹하여 ./main을 생성하시오.
 - 'make all' 실행 시 ./lib 디렉토리에 ./libft.a가 없을 시 ./lib/Makefile을 실행하여 libft.a를 생성한다.

< 제한 사항 >
 - .c 파일들을 할당한 변수를 함수로 치환하여 .o 파일을 할당할 변수로 정의하시오.
 - 패턴 Rule을 사용하여 오브젝트 파일 생성 규칙을 정의하시오
 - Rule의 Recipe 작성 시 Target과 Dependency를 적절한 자동 변수(Automatic Variables)를 사용하여 작성하세요.
 - Rule을 변수만으로 작성하시오.
 - 적절한 변수를 할당하시오.
 - 리링크되지 않아야 합니다.
```

**Solve**

```bash
SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./lib/
HEADER_DIR = ./include/

NAME = main
SRC_NAME = main.c fourth.c
SRCS = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I$(LIB_DIR) -I$(HEADER_DIR)

.PHONY : all clean fclean re run
all : $(NAME)
clean :
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean
fclean : clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean
re : fclean all
run : all
	./$(NAME)

$(NAME) : $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(LIB) :
	make -C $(LIB_DIR) all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
```

### **Makefile for libft**

```bash
NAME = libft.a

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c
OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re
all : $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

---

# 참고

### **학습 및 참고 자료**

[GitHub - Likilee/Makefile_Training](https://github.com/Likilee/Makefile_Training)

[GNU make](https://www.gnu.org/software/make/manual/make.html)

[Makefile 치트 시트](https://www.notion.so/Makefile-2fc3afd6202340faacd07ad0a648d22a)