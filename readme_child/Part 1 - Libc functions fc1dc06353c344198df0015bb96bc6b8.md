# Part 1 - Libc functions

### **`isalpha()`**

- SYNOPSIS
    
    ```c
    #include <ctype.h>
    int	isalpha(int c);
    ```
    
- DESCRIPTION
    - argument가 isupper or islower인지 test하는 함수
    - argument의 value는 (unsigned char or EOF 값)으로 표현되어야 한다.
- RETURN VALUE
    - True -> non-zero
    - False -> 0
- Solve
    
    ```c
    int	ft_isalpha(int c)
    {
    	if (65 <= c && c <= 90)
    		return (1);
    	if (97 <= c && c <= 122)
    		return (1);
    	return (0);
    }
    ```
    
- Notes
    1. argument를 int 타입으로 받아야 하는 이유? 받아도 되는 이유?
        - C언에서 문자를 넣으면 자동으로 아스키 코드에 해당하는 숫자로 들어간다.
        - `char` 타입보다 범위가 더 큰 `int` 타입으로 받음으로써 인자를 안전하게 받을 수 있다.
            - `char` 타입으로 받으면 언더플로우or오버플로우가 나는데, 이렇게 되면 의도한 동작을 할 수 없다. `int`로 받으면 보다 안전하게 받을 수 있다.

### **`isdigit()`**

- SYNOPSIS
    
    ```c
    #include <ctype.h>
    int	isdigit(int c);
    ```
    
- DESCRIPTION
    - argument가 decimal digit character인지 test하는 함수
- RETURN VALUE
    - True -> non-zero
    - False -> 0
- Solve
    
    ```c
    int	ft_isdigit(int c)
    {
    	if (48 <= c && c <= 57)
    		return (1);
    	return (0);
    }
    ```
    

### **`isalnum()`**

- SYNOPSIS
    
    ```c
    #include <ctype.h>
    int	isalnum(int c);
    ```
    
- DESCRIPTION
    - argument가 isalpha() 또는 isdigit()이 참인지 test하는 함수
- RETURN VALUE
    - True -> non-zero
    - False -> 0
- Solve
    
    ```c
    int	ft_isalnum(int c)
    {
    	if (ft_isalpha(c) || ft_isdigit(c))
    		return (1);
    	return (0);
    }
    ```
    

### **`isascii()`**

- SYNOPSIS
    
    ```c
    #include <ctype.h>
    int	isascii(int c);
    ```
    
- DESCRIPTION
    - argument가 ASCII character인지 test하는 함수
    - 0 ~ 127 (10진수)
- RETURN VALUE
    - True -> non-zero
    - False -> 0
- Solve
    
    ```c
    int	ft_isascii(int c)
    {
    	if (0 <= c && c <= 127)
    		return (1);
    	return (0);
    }
    ```
    

### **`isprint()`**

- SYNOPSIS
    
    ```c
    #include <ctype.h>
    int isprint(int c);
    ```
    
- DESCRIPTION
    - argument가 printable한지 test하는 함수
    - 32 ~ 126 (10진수)
- RETURN VALUE
    - True -> non-zero
    - False -> 0
- Solve
    
    ```c
    int	ft_isprint(int c)
    {
    	if (32 <= c && c <= 126)
    		return (1);
    	return (0);
    }
    ```
    

### **`strlen()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    size_t strlen(const char *s);
    ```
    
- DESCRIPTION
    - 문자열 `s`의 길이를 계산하는 함수
- RETURN VALUE
    - Terminating NUL character 앞에 오는 문자의 수
- Solve
    
    ```c
    #include <stdlib.h>
    
    size_t	ft_strlen(const char *s)
    {
    	size_t	size;
    
    	size = 0;
    	while (s[size])
    		size++;
    	return (size);
    }
    ```
    
- Notes
    1. `size_t` 는 무엇인가?
        - 가장 큰 사이즈를 담을 수 있는 `unsigned 정수형`
        - 해당 시스템에서 최대 크기의 데이터를 표현하는 타입으로서, 반드시 `unsigned 정수형`으로 나타낸다.
        - 32bit 머신
            - 32bit 사이즈의 `unsigned 정수형 (unsigned int)`
            - 크기: `4byte(32bit)`
        - 64bit머신
            - 64bit 사이즈의 `unsigned 정수형 (unsigned long long)`
            - 크기: `8byte(64bit)`
        - `unsigned int`는 운영체제에 따라 사이즈가 달라지기 때문에 고정된 `size_t`를 사용한다.
    2. 매개변수를 `const char *` 로 선언한 무엇인가?
        - char pointer 변수가 가리키는 곳의 값을 수정할 수 없도록 상수취급하기 위함
        - `const char *s = "abc"`가 들어오면, s가 가리키는 곳의 값은 `"abc"`로 고정되고, 수정할 수 없다. 단, s의 값을 바꿀 순 있다. (다른 곳을 가리키도록 할 수 있음)

### **`memset()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    void *	memset(void *b, int c, size_t len);
    ```
    
- DESCRIPTION
    - `pointer b` 가 가리키는 메모리 영역의 `len byte` 만큼을 모두 `(unsigned char) c` 로 채운다.
    - Byte 단위로 메모리 영역을 세팅한다.
- RETURN VALUE
    - first argument (`pointer b`)
- Solve
    
    ```c
    #include <stdlib.h>
    
    void	*ft_memset(void *b, int c, size_t len)
    {
    	unsigned char	*ptr;
    	size_t			i;
    
    	ptr = (unsigned char *)b;
    	i = 0;
    	while (i < len)
    		ptr[i++] = (unsigned char)c;
    	return (b);
    }
    ```
    
- Notes
    1. pointer를 `void *` 타입으로 받고, `unsigned char *` 로 형변환하는 이유
        - `void *` 로 받는 이유
            - 기본적으로 C 언어는 자료형이 다른 포인터끼리 메모리 주소를 저장하면 컴파일 경고(warning)가 발생한다. 하지만 void 포인터는 자료형이 정해지지 않은 특성때문에 어떤 자료형으로 된 포인터든 모두 저장할 수 있다. 반대로 다양한 자료형으로 된 포인터에도 void 포인터를 저장할 수 있다. 이런 특성 때문에 void 포인터는 범용 포인터라고 한다.
            - 모든 타입의 포인터를 인자로 받을 수 있게 하도록하기 위해 `void *` 타입으로 선언
        - `unsigned char *` 로 형변환하는 이유
            - void 포인터는 역참조를 할 수 없기 때문에 함수 내부에서 참조하기 위해서는 다른 자료형으로 형변환을 해줘야한다.
            - `metset()` 함수는 byte 단위로 메모리 영역을 setting하는 함수이기 때문에 자료형의 크기가 1 byte인 `unsigned char` 타입으로 형변환을 해줘야한다.
            - `unsigned` 로 형변환을 해주는 이유는 **C 언어 표준에서는 unsigned char만을 패딩이 없는 자료형으로 보증**하기 때문이다.
                - 패딩은 길이를 맞추기 위해 추가하는 쓸 데 없는 비트를 의미한다.
                - ex) `true, false` 를 표현하기 위해 1, 0 만을 값으로 갖는 자료형을 만든다고 하면 1, 0만 있으면 되기 때문에 1비트만 있으면 충분하다. 하지만, 메모리에 데이터를 쓰고 읽는 것은 최소 바이트 단위로 이루어지기 때문에, 1바이트(8비트)를 모두 써서 `00000000, 00000001` 라는 형태로 0과 1을 표현할 수 밖에 없다. 이 때 위처럼 깔끔하게 유효한 비트를 맨 오른쪽에 넣을 수도 있지만 "우리는 유효한 비트를 세 번째 자리에 넣읍시다" 라고 약속하고 `true, false` 를 `00000000, 00100000` 로 정의할 수도 있다. 이 때 저 무의미한 0들, 오직 자릿수 맞추기 용도인 저 0들을 패딩비트라고 부른다.
                - **C 언어 표준에서는 문자 단위로 조작할 때는 `char`, byte 단위로 조작할 때는 `unsigned char` 를 사용하라고 한다.**
    2. memory 영역을 setting할 argument를 `int` 타입으로 받는 이유
        - `unsigned char` 타입으로 받으면 0 ~ 255 외의 값에 대해 알 수 없기 때문에 `int` 로 받는다.

### **`bzero()`**

- SYNOPSIS
    
    ```c
    #include <strings.h>
    void	bzero(void *s, size_t n);
    ```
    
- DESCRIPTION
    - `pointer s` 가 가리키는 메모리 영역의 `n byte` 만큼을 0으로 채운다.
- RETURN VALUE
    - X
- Solve
    
    ```c
    #include <stddef.h>
    
    void	ft_bzero(void *s, size_t n)
    {
    	unsigned char	*ptr;
    	size_t			i;
    
    	ptr = (unsigned char *) s;
    	i = 0;
    	while (i < n)
    		ptr[i++] = 0;
    }
    ```
    

### **`memcpy()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    
    void *	memcpy(void *restrict dst, const void *restrict src, size_t n);
    ```
    
- DESCRIPTION
    - 메모리 영역 `src` 에서 메모리 영역 `dst` 로 `n byte` 만큼 복사한다. 메모리 영역은 겹치지 않아야 한다. 메모리 영역이 겹치는 경우(overlap) `memmove()` 함수를 사용해야 한다.
- RETURN VALUE
    - 포인터 `dst`
- Solve
    
    ```c
    #include <stddef.h>
    
    void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
    {
    	unsigned char	*dst_p;
    	unsigned char	*src_p;
    	size_t			i;
    
    	if (dst == src)
    		return (dst);
    	dst_p = (unsigned char *) dst;
    	src_p = (unsigned char *) src;
    	i = 0;
    	while (i < n)
    	{
    		dst_p[i] = src_p[i];
    		i++;
    	}
    	return (dst);
    }
    ```
    
- Notes
    1. `restrict`
        - *'포인터 변수의 주소가 겹치지 않는다'**고 컴파일러에게 알려줌으로써, 최적화를 할 수있도록 하는 키워드
        - ex)
            - 위와 같이 포인터를 역참조하여 값을 증가시키는 두 함수가 있다고 하면, 컴파일러는 이 두 함수를 다르게 해석한다.
            
            ```c
            // add1()
            load R1 ← *c
            load R2 ← *a
            add R2 += R1
            set R2 → *a
            
            load R1 ← *c
            load R2 ← *b
            add R2 += R1
            set R2 → *b
            ```
            
            ```c
            // add2()
            load R1 ← *c
            load R2 ← *a
            add R2 += R1
            set R2 → *a
            
            load R2 ← *b
            add R2 += R1
            set R2 → *b
            ```
            
            - `add1()` 에서는 이미 R1 레지스터(임시공간)에 로드했던 `c` 를 또 한번 로드한다. 그 이유는 다른 포인터에 의해서 `c` 의 값이 바뀌었을 가능성이 있기 때문이다.
            - `add2()` 에서는 이전에 로드했던 `c` 값이 아직 R1 레지스터에 존재하고, 컴파일러는 이 공간이 **다른 포인터에 의해 값이 변경되지 않는다**고 알고있기 때문에 기존 R1의 값을 그대로 사용한다.
            - `restrict` 키워드는 명시적 제약이다. `restrict` 포인터를 써놓고 같은 메모리를 역참조하는 포인터를 만들어도 컴파일 에러를 발생하지 않기 때문에 논리적 오류를 범할 가능성이 있다.

### **`memmove()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    void	*memmove(void *dst, const void *src, size_t len);
    ```
    
- DESCRIPTION
    - `src`에서 `dst`로 `len byte` 만큼 복사한다.
    - `src`와 `dst`는 overlap될 수 있다. 복사는 항상 non-destructive manner(비파괴적인 방식)으로 수행된다.
- RETURN VALUE
    - 포인터 `dst`
- Solve
    
    ```c
    #include <stddef.h>
    
    void	*ft_memmove(void *dst, const void *src, size_t len)
    {
    	size_t	i;
    
    	if (len == 0 || dst == src)
    		return (dst);
      // src < dst이고, dst와 src가 overlap되면 뒤에서부터 copy한다.
    	if (src < dst && dst < src + len)
    	{
    		while (0 <= --len)
    		{
    			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
          // len은 항상 0 이상이기 때문에, break point를 설정해준다.
    			if (len == 0)
    				break ;
    		}
    	}
    	else
    	{
    		i = 0;
    		while (i < len)
    		{
    			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
    			i++;
    		}
    	}
    	return (dst);
    }
    ```
    
- Notes
    1. **비파괴적인 방식으로 복사**한다는게 무엇인가?
        - `dst`와 `src`의 메모리 영역이 overlap되면 복사하는 과정에서 값이 오염될 수 있다. 오염되는 것을 방지하는 방식을 비파괴적인 방식이라고 한다.

### **`strlcpy()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    size_t	strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
    ```
    
- DESCRIPTION
    - 문자열을 복사한다. `strncpy()` 보다 안전하고 일관성 있고 오류가 적은 대체품으로 설게되었다.
    - `dst` 버퍼의 전체 크기를 사용하고, 공간이 있는 경우 NUL-termination을 보장한다. NUL을 위한 공간은 `dstsize`에 포함되어야 한다.
    - `src`에서 `dst`로 `dstsiz - 1` 글자를 복사하고, `dstsize`가 0이 아닌 경우 NUL 종료 문자를 넣는다.
    - `dst`와 `src`가 overlap되는 경우, 동작이 정의되지 않는다.
- RETURN VALUE
    - `src`의 길이(복사를 시도한 문자열의 총 길이)
    - `return value >= dstsize` 이면 복사가 제대로 된 것이 아니다. 이를 처리하는 것은 호출자의 책임이다.
- RETURN VALUE
- Solve
    
    ```c
    #include <stddef.h>
    
    size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
    {
    	size_t	i;
    
    	i = 0;
      // dstsize - 1까지 반복 or src 문자열 끝까지 반복
    	while (i + 1 < dstsize && src[i] != '\0')
    	{
    		dst[i] = src[i];
    		i++;
    	}
      // dstsize가 0이 아닌 경우 NUL-termintating 문자 삽입
      if (dstsize != 0)
    		dst[i] = '\0';
    	while (src[i] != '\0')
    		i++;
    	return (i);
    }
    ```
    

### **`strlcat()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    size_t	strlcat(char *dst, const char *src, size_t dstsize);
    ```
    
- DESCRIPTION
    - 문자를 연결한다. `strncat()`보다 안전하고 일관성 있고 오류가 적은 대체품으로 설계되었다.
    - `dst` 버퍼의 전체 크기를 사용하고, 공간이 있는 경우 NUL-termination을 보장한다. NUL을 위한 공간은 `dstsize`에 포함되어야 한다.
    - `dst`의 끝에 `src` 문자열을 연결한다. 최대 `dstsize - strlen(dst) - 1` 글자를 추가한다. 그런 다음 `dstsize == 0` 이거나 `dst` 문자열이 `dstsize`보다 길지 않는 한 NUL 종료된다. (실제로 이것은 `dstsize`가 올바르지 않거나 `dst`가 적절한 문자열이 아님을 의미하므로 발생해서는 안된다.)
- RETURN VALUE
    - (`dst` 초기 길이 / `dstsize` 중 작은 값) + `src`의 길이
- Solve
    
    ```c
    #include "libft.h"
    #include <stddef.h>
    
    size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
    {
    	size_t	dst_len;
    	size_t	src_len;
    	size_t	i;
    
    	dst_len = ft_strlen(dst);
    	src_len = ft_strlen(src);
      // dstsize == 0 이거나 dst 문자열이 dstsize 보다 길면
    	if (dstsize == 0 || dstsize < dst_len)
    		return (dstsize + src_len);
    	i = 0;
    	while (dst_len + i + 1 < dstsize && src[i])
    	{
    		dst[dst_len + i] = src[i];
    		i++;
    	}
    	dst[dst_len + i] = '\0';
    	return (dst_len + src_len);
    }
    ```
    
- Notes
    1. return value: **(`dst` 초기 길이 / `dstsize` 중 작은 값) + `src`의 길이**인 이유
        - `dst` 길이가 `dstsize`보다 큰 경우는 문자열을 이어붙일 수가 없다.
        - `dst` 문자열이 잘리는지 감지를 간단하게 하기 위해 수행된다.

### **`toupper()`**

- SYNOPSIS
    
    ```c
    #include <ctype.h>
    int	toupper(int c);
    ```
    
- DESCRIPTION
    - 소문자를 해당 대문자로 변환한다.
    - argument는 `unsigned char` or `EOF` 값으로 표현할 수 있어야 한다.
- RETURN VALUE
    - argument에 대응되는 대문자가 있는 경우 => return 해당 대문자
    - else => return argument 그대로
- Solve
    
    ```c
    int	ft_toupper(int c)
    {
    	if ('a' <= c && c <= 'z')
    		return (c - ('a' - 'A'));
    	return (c);
    }
    ```
    

### **`tolower()`**

- SYNOPSIS
    
    ```c
    #include <ctype.h>
    int	tolower(int c);
    ```
    
- DESCRIPTION
    - 대문자를 해당 소문자로 변환한다.
    - argument는 `unsigned char` or `EOF` 값으로 표현할 수 있어야 한다.
- RETURN VALUE
    - argument에 대응되는 소문자가 있는 경우 => return 해당 소문자
    - else => return argument 그대로
- Solve
    
    ```c
    int	ft_tolower(int c)
    {
    	if ('A' <= c && c <= 'Z')
    		return (c - ('A' - 'a'));
    	return (c);
    }
    ```
    

### **`strchr()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    char	*strchr(const char *s, int c);
    ```
    
- DESCRIPTION
    - `s`가 가리키는 문자열에서 `c` 문자가 처음 나타나는 위치를 찾는다. (Null 문자도 문자열의 일부로 간주)
- RETURN VALUE
    - 문자의 위치를 찾으면 => return 문자에 대한 포인터
    - 못찾으면 => return NULL
- Solve
    
    ```c
    #include <stddef.h>
    
    char	*ft_strchr(const char *s, int c)
    {
    	int		i;
    
    	i = 0;
    	while (s[i])
    	{
    		if (s[i] == (char)c)
    			return ((char *)s + i);
    		i++;
    	}
    	if (s[i] == (char)c)
    		return ((char *)s + i);
    	return (NULL);
    }
    ```
    

### **`strrchr()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    char	*strrchr(const char *s, int c);
    ```
    
- DESCRIPTION
    - `s`가 가리키는 문자열에서 `c` 문자가 마지막으로 나타나는 위치를 찾는다. (Null 문자도 문자열의 일부로 간주)
- RETURN VALUE
    - 문자의 위치를 찾으면 => return (문자에 대한 포인터)
    - 못찾으면 => return NULL
- Solve
    
    ```c
    #include <stddef.h>
    
    char	*ft_strrchr(const char *s, int c)
    {
    	char	*result;
    	int		i;
    
    	result = NULL;
    	i = 0;
    	while (s[i])
    	{
    		if (s[i] == (char)c)
    			result = (char *)s + i;
    		i++;
    	}
    	if (s[i] == (char)c)
    		result = (char *)s + i;
    	return (result);
    }
    ```
    

### **`strncmp()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    int	strncmp(const char *s1, const char *s2, size_t n);
    ```
    
- DESCRIPTION
    - null 문자로 끝나는 문자열 `s1`과 `s2`를 사전식으로 비교한다.
    - `n`개 이하의 문자를 비교한다. `strncmp()`는 바이너리 데이터가 아닌 문자열을 비교하도록 설계되었기 때문에 `'\0'` 문자 뒤에 나타나는 문자는 비교되지 않는다.
    - 아스키 코드값으로 비교한다.
- RETURN VALUE
    - `s1` 문자열과 `s2` 문자열의 문자가 다른 시점의 아스키 코드값의 차이를 리턴한다.
    - `s1 == s2` => `return 0`
    - `s1 < s2` => `return 음의 정수`
    - `s1 > s2` => `return 양의 정수`
- Solve
    
    ```c
    #include <stddef.h>
    
    int	ft_strncmp(const char *s1, const char *s2, size_t n)
    {
    	size_t	i;
    
    	i = 0;
    	while (s1[i] && s2[i] && i < n)
    	{
    		if (s1[i] != s2[i])
    			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    		i++;
    	}
    	if (i == n)
    		return (0);
    	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    }
    ```
    
- Notes
    1. `(unsigned char)` 타입으로 캐스팅해서 비교하는 이유
        - `signed char`의 경우 음수부호를 포함하기 때문에, 오버플로우가 발생했을 때 음수 값으로 변한다. 그럼 잘못된 대소비교결과값을 뱉어낼 수 있다.
        - ex)
            
            ```c
            s1[0] = 128;
            s2[0] = 0;
            일 때, char 타입의 경우, 128은 -128로 오버플로우된다.
            이를 비교하면 대소비교의 결과가 정반대가 된다.
            ```
            

### **`memchr()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    void	*memchr(const void *s, int c, size_t n);
    ```
    
- DESCRIPTION
    - `c`의 첫 번째 인스턴스에 대해 `s`가 가리키는 메모리 영역의 초기 `n` byte를 스캔한다. `c`와 `s`가 가리키는 메모리 영역의 바이트는 모두 `unsigned char`로 해석된다.
    - 메모리 영역 `s`의 처음부터 `n` byte에서 `c`가 처음 나타나는 위치를 찾는다.
- RETURN VALUE
    - 위치를 찾으면 => return 그 위치에 대한 포인터
    - 못찾으면 => return NULL
- Solve
    
    ```c
    #include <stddef.h>
    
    void	*ft_memchr(const void *s, int c, size_t n)
    {
    	size_t	i;
    
    	i = 0;
    	while (i < n)
    	{
    		if (((unsigned char *)s)[i] == (unsigned char)c)
    			return ((void *)s + i);
    		i++;
    	}
    	return (NULL);
    }
    ```
    

### **`memcmp()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    int	memcmp(const void *s1, const void *s2, size_t n);
    ```
    
- DESCRIPTION
    - 메모리 영역 `s1`과 `s2`의 처음 `n` byte를 비교한다.
- RETURN VALUE
    - `s1`이 `s2` 보다 작으면 음의 정수, 같으면 0, 크면 양의 정수
        - `s1 == s2` ⇒ `return 0`
        - `s1 < s2` => `return 음의 정수`
        - `s1 > s2` => `return 양의 정수`
- Solve
    
    ```c
    #include <stddef.h>
    
    int	ft_memcmp(const void *s1, const void *s2, size_t n)
    {
    	unsigned char	*s1_p;
    	unsigned char	*s2_p;
    	size_t			i;
    
    	s1_p = (unsigned char *)s1;
    	s2_p = (unsigned char *)s2;
    	i = 0;
    	while (i < n)
    	{
    		if (s1_p[i] != s2_p[i])
    			return (s1_p[i] - s2_p[i]);
    		i++;
    	}
    	return (0);
    }
    ```
    

### **`strnstr()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    char *strnstr(const char *haystack, const char *needle, size_t len);
    ```
    
- DESCRIPTION
    - `haystack` 문자열의 `len` 길이 만큼에서 null 종료되는 문자열 `needle`의 첫 번째 발생 위치를 찾는다.
    - `strnstr()`은 freeBSD specific API이기 때문에 이식성이 문제가 되지 않는 경우에만 사용해야 한다.
- RETURN VALUE
    - `needle`이 빈 문자열이면 => return `haystack`
    - `needle`을 못찾으면 => return `NULL`
    - `needle`을 찾으면 => return (`needle`의 첫 번째 문자에 대한 포인터)
- Solve
    
    ```c
    #include "libft.h"
    // ft_strlen(), ft_strncmp()
    
    // len : haystack 문자열의 len 길이만큼만 탐색한다.
    char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
    {
    	size_t	len_h;
    	size_t	len_n;
    	size_t	i;
    
    	if (needle[0] == '\0')
    		return ((char *)haystack);
    	len_h = ft_strlen(haystack);
    	len_n = ft_strlen(needle);
    	i = 0;
      
    	while ((i + len_n <= len) && (i + len_n <= len_h))
    	{
    		if (haystack[i] == needle[0]
    			&& ft_strncmp(&haystack[i], needle, len_n) == 0)
    			return ((char *)&haystack[i]);
    		i++;
    	}
    	return (NULL);
    }
    ```
    
- Notes
    1. `haystack`과 `needle`은 무슨 뜻인가?
        - 속담: Needle in a haystack. (건초더미에서 바늘 찾기)
        - `haystack` - 스캔할 기본 C 문자열을 비유
        - `needle` - `haystack` 내에서 검색할 작은 문자열을 비유
    2. freeBSD specific API는 무슨 뜻인가?
        - freeBSD란 유닉스 계열 운영체제를 말한다. freeBSD specific API란 말은 strnstr 함수는 운영체제에 specific하므로 다른 운영체제에 이식할 때는 쓰지 않는다는 뜻이다.

### **`atoi()`**

- SYNOPSIS
    
    ```c
    #include <stdlib.h>
    int	atoi(const char *str);
    ```
    
- DESCRIPTION
    - `str`이 가리키는 문자열의 초기 부분을 int 타입으로 변환한다.
        - 다음과 같다.
            - `(int)strtol(str, (char **)NULL, 10);`
- RETURN VALUE
    - 변환성공 => return 변환한 int형 숫자
    - 변환가능한 숫자가 없는 경우 => return 0
- Solve
    
    ```c
    #include <limits.h>
    
    char	*pass_space(const char *str)
    {
    	int	i;
    
    	i = 0;
    	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
    		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
    		i++;
    	return ((char *)str + i);
    }
    
    int	check_sign(char **str_p)
    {
    	if (**str_p == '-')
    	{
    		(*str_p)++;
    		return (-1);
    	}
    	else if (**str_p == '+')
    		(*str_p)++;
    	return (1);
    }
    
    int	convert_to_int(char *str, int sign)
    {
      // (cutoff, cutlim)으로 overflow와 underflow를 감지한다.
    	unsigned long	cutoff;
    	unsigned long	cutlim;
      // 실제 변환할 값을 저장할 변수
    	unsigned long	num;
      // overflow, underflow에 대한 flag
    	int				over;
    
    	// sign == 1 -> LONG_MAX == (cutoff + cutlim)
      // sign == -1 -> LONG_MIN == -(cutoff + cutlim)
    	cutoff = LONG_MAX / 10;
    	cutlim = LONG_MAX % 10;
    	if (sign == -1)
    		cutlim = -(LONG_MIN % 10);
    	num = 0;
    	over = 0;
    	while ('0' <= *str && *str <= '9' && *str)
    	{
    		if (over == 1 || num > cutoff \
    				|| (num == cutoff && (unsigned long)*str - '0' > cutlim))
    			over = 1;
    		else
    			num = num * 10 + (*str - '0');
    		str++;
    	}
    	if (over && sign == 1)
    		num = LONG_MAX;
    	else if (over && sign == -1)
    		num = LONG_MIN;
    	return (sign * (int)num);
    }
    
    int	ft_atoi(const char *str)
    {
    	char	*tmp_str;
    	int		sign;
    
    	tmp_str = pass_space(str);
    	sign = check_sign(&tmp_str);
    	return (convert_to_int(tmp_str, sign));
    }
    ```
    
- Notes
    1. `long strtol(const char *restrict str, char **restrict endptr, int base);`
        - 원본 `atoi`는 int 오버플로우는 그냥 무시되고 long 오버플로우부터 결과값이 바뀐다.
        - 원형함수 `atoi`는 `(int)strtol(str, char **)NULL, 10)`을 리턴한다.
        - `strtol();`
            - `strtol`함수는 `str`문자열에 있는 초기숫자를 base진수의 long 타입 정수로 변환해서 리턴을 해준다.
            - overflow가 발생하면, `LONG_MAX` 값을 리턴한다.
            - underflow가 발생하면, `LONG_MIN` 값을 리턴한다.

### **`calloc()`**

- 이 함수는 외부 함수 `malloc` 을 사용해 구현
- SYNOPSIS
    
    ```c
    #include <stdlib.h>
    void	*calloc(size_t count, size_t size);
    ```
    
- DESCRIPTION
    - 메모리를 할당한다. 할당된 메모리는 AltiVec 및 SSE 관련 유형을 포함한 모든 데이터 유형에 사용할수 있도록 정렬된다.
    - `free()` 함수로 할당된 메모리를 해제한다.
    - `malloc()` 함수는 size 바이트의 메모리를 할당하고 할당된 메모리에 대한 포인터를 반환한다.
    - `calloc()` 함수는 `size` 바이트의 개체를 `count` 만큼 메모리를 할당하고 할당된 메모리에 대한 포인터를 반환한다. 할당된 메모리는 값이 0인 바이트로 채워진다.
- RETURN VALUE
    - 메모리 할당 성공 => return (할당된 메모리에 대한 포인터)
    - 실패 => return NULL
- Solve
    
    ```c
    #include <stdlib.h>
    #include "libft.h"
    
    void	*ft_calloc(size_t count, size_t size)
    {
    	void	*memory;
    	
      // overflow 상황에 대한 예외처리
    	if (size != 0 && (count * size) / size != count)
    		return (NULL);
    	memory = malloc(count * size);
    	if (memory == NULL)
    		return (NULL);
    	ft_bzero(memory, count * size);
    	return (memory);
    }
    ```
    

### **`strdup()`**

- SYNOPSIS
    
    ```c
    #include <string.h>
    char	*strdup(const char *s1);
    ```
    
- DESCRIPTION
    - 문자열 `s1`의 복사본을 위한 충분한 메모리를 할당하고 복사를 수행하고 이에 대한 포인터를 반환한다.
- RETURN VALUE
    - 성공 => return 복사한 공간에 대한 포인터
    - 실패 => return NULL
- Solve
    
    ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_strdup(const char *s1)
    {
    	int		len;
    	char	*dst;
    	int		i;
    
    	len = ft_strlen(s1);
    	dst = (char *)malloc(sizeof(char) * len);
    	if (dst == NULL)
    		return (NULL);
    	i = 0;
    	while (i < len)
    	{
    		dst[i] = s1[i];
    		i++;
    	}
    	return (dst);
    }
    ```