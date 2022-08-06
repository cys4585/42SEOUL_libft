# Part 2 - Additional functions

### **`substr()`**

- Prototype
    
    ```c
    char	*ft_substr(char const *s, unsigned int start, size_t len);
    ```
    
- Parameters
    - `s` : 부분 문자열(substring)을 생성할 원본 문자열
        
        > The string from which to create the substring.
        > 
    - `start`: 부분 문자열에 넣을 문자열 `s`의 맨 처음 인덱스
        
        > The start index of the substring in the string s.
        > 
    - `len`: 부분 문자열의 최대 길이
        
        > The maximum length of the substring.
        > 
- Return value
    
    > The substring. NULL if the allocation fails.
    > 
- External functions
    - `malloc`
- Description
    - `malloc()`을 이용하여 메모리를 할당받은 후, 원본 문자열 `s`로부터 부분 문자열을 생성하여 반환한다. 부분 문자열은 인덱스 `start` 부터 시작하며, 최대 길이 `len`을 갖는다.
        
        > Allocates (with malloc(3)) and returns a substring from the string s. The substring begins at index start and is of maximum size len.
        > 
- Solve
    
    ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_substr(char const *s, unsigned int start, size_t len)
    {
    	char			*sub;
    	unsigned int	i;
    	size_t			s_len;
    
      if (s == NULL)
        return (NULL);
    	s_len = ft_strlen(s);
      // start 인덱스가 말이 안되면 빈문자열을 만들어주기 위함
    	if (s_len <= start)
    		len = 0;
      // s 문자열로부터 복사할 수 있는 문자열의 길이가 len 값 보다 작으면 할당할 메모리 크기가 len 보다 작아도 됨
    	else if (s_len - start < len)
    		len = s_len - start;
      //  null 문자 자리 +1 해주기
    	sub = (char *)malloc(sizeof(char) * (len + 1));
      // 공간 할당 실패 시 return NULL
    	if (sub == NULL)
    		return (NULL);
    	i = 0;
    	while (i < len)
    	{
    		sub[i] = s[start + i];
    		i++;
    	}
    	sub[i] = '\0';
    	return (sub);
    }
    ```
    
- Notes
    1. `char const *s`의 의미?
    - `const char *s`는 `char const *s`와 같은 의미이다. 포인터 변수 `s`가 가리키는 곳의 값을 수정할 수 없다. 포인터 변수 `s`의 값은 수정할 수 있다. (다른 곳을 가리키게 할 수 있다.)
    - `char * const s`는 포인터 변수 `s`의 값을 수정할 수 없다. (다른 곳을 가리키게 할 수 없다.) 포인터 자체가 상수화 된 것이다.

### **`strjoin()`**

- Prototype
    
    ```c
    char	*ft_strjoin(char const *s1, char const *s2);
    ```
    
- Parameters
    - `s1`: 접두 문자열
        
        > The prefix string.
        > 
    - `s2`: 접미 문자열
        
        > The suffix string.
        > 
- Return value
    
    > The new string. NULL if the allocation fails.
    > 
- External functions
    - `malloc`
- Description
    - `malloc()`을 활용해 새로운 문자열 공간을 할당하고, 문자열 `s1`과 `s2`를 연결한 새로운 문자열을 반환한다.
        
        > Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of s1 and s2.
        > 
- Solve
    
    ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_strjoin(char const *s1, char const *s2)
    {
    	char	*new_str;
    	size_t	len_s1;
    	size_t	len_s2;
    
    	if (s1 == NULL && s2 == NULL)
    		return (NULL);
    	if (s1 == NULL)
    		return (ft_strdup(s2));
    	if (s2 == NULL)
    		return (ft_strdup(s1));
    	len_s1 = ft_strlen(s1);
    	len_s2 = ft_strlen(s2);
    	new_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    	if (new_str == NULL)
    		return (NULL);
    	ft_strlcpy(new_str, s1, len_s1 + 1);
    	ft_strlcat(new_str, s2, len_s1 + len_s2 + 1);
    	return (new_str);
    }
    ```
    

### **`strtrim()`**

- Prototype
    
    ```c
    char	*ft_strtrim(char const *s1, char const *set);
    ```
    
- Parameters
    - `s1`: 양 쪽을 잘라낼 원본 문자열
        
        > The string to be split.
        > 
    - `s2`: 제거될 문자들의 집합
        
        > The delimiter character.
        > 
- Return value
    - 문자가 제거된 문자열. 할당 실패 시, NULL
        
        > The trimmed string. NULL if the allocation fails.
        > 
- External functions
    - `malloc`
- Description
    - `malloc()`을 이용하여 메모리를 할당하고, `set`에 지정된 문자들이 문자열의 시작과 끝에서 제거된 `s1` 문자열의 사본을 반환한다.
        
        > Allocates (with malloc()) and returns a copy of s1 with the characters specified in set removed from the beginning and the end of the string.
        > 
- Solve
    
    ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_strtrim(char const *s1, char const *set)
    {
    	int		begin_idx;
    	int		end_idx;
    
    	if (s1 == NULL)
    		return (NULL);
    	if (set == NULL)
    		return (ft_strdup(s1));
    	begin_idx = 0;
    	while (s1[begin_idx] && ft_strchr(set, s1[begin_idx]))
    		begin_idx++;
    	end_idx = ft_strlen(s1) - 1;
    	while (0 <= end_idx && ft_strchr(set, s1[end_idx]))
    		end_idx--;
    	if (end_idx < begin_idx)
    		return (ft_strdup(""));
    	return (ft_substr(s1, begin_idx, end_idx - begin_idx + 1));
    }
    ```
    

### **`split()`**

- Prototype
    
    ```c
    char	**ft_split(char const *s, char c);
    ```
    
- Parameters
    - `s`: 분할할 문자열
        
        > The string to be split.
        > 
    - `c`: 구분자
        
        > The delimiter character.
        > 
- Return value
    - split을 통해 분할된 문자열의 배열
        
        > The array of new strings resulting from the split. NULL if the allocation fails.
        > 
- External functions
    - `malloc`, `free`
- Description
    - `malloc()`을 이용하여 메모리를 할당하고, 구분자 `c`를 기준으로 문자열 `s`를 분할하여 그 결과를 담은 새로운 문자열 배열을 반환한다. 문자열 배열의 끝은 NULL 포인터로 끝나야 한다.
        
        > Allocates (with malloc()) and returns an array of strings obtained by splitting s using the character c as a delimiter. The array must end with a NULL pointer.
        > 
- Solve
    
    ```c
    #include <stdlib.h>
    #include "libft.h"
    
    // 문자열을 분할해서 담을 배열의 크기를 계산하는 함수
    int	count_size(char const *s, char c)
    {
    	int	cnt;
    	int	flag;
    	int	i;
    
    	cnt = 0;
      // split 할 지점을 판별하기 위한 flag
    	flag = 0;
    	i = 0;
    	while (s[i])
    	{
    		if (flag == 0 && s[i] != c)
    			flag = 1;
    		else if (flag == 1 && s[i] == c)
    		{
    			cnt++;
    			flag = 0;
    		}
    		i++;
    	}
    	if (flag == 1)
    		cnt++;
    	return (cnt);
    }
    
    // 문자열을 delimiter를 기준으로 분할해서 배열에 담는 함수
    int	split_str(char **dst_arr, char const *s, char c, int s_len)
    {
    	int		start;
    	int		flag;
    	int		i;
    
    	start = 0;
    	flag = 0;
    	i = 0;
      // s 문자열의 null-terminate 문자까지 반복문 돈다. (마지막이 c 가 아닌 문자로 끝나도 배열에 분할한 문자열을 담을 수 있도록 하기 위함)
    	while (i <= s_len)
    	{
    		if (flag == 0 && s[i] != c)
    		{
    			start = i;
    			flag = 1;
    		}
    		else if (flag == 1 && (s[i] == c || s[i] == '\0'))
    		{
    			*dst_arr = ft_substr(s, start, i - start);
          // 공간할당에 실패하면 비정상종료임을 알려줌으로써 공간 해제(free)를 할 수 있도록 한다.
    			if (*dst_arr == NULL)
    				return (0);
    			dst_arr++;
    			flag = 0;
    		}
    		i++;
    	}
    	return (1);
    }
    
    // 할당했던 모든 공간을 해제 (각 배열의 요소들도 각각 동적할당을 해줬기 때문에 직접 해제해줘야 한다.)
    void	array_free(char **arr)
    {
    	int	i;
    
    	i = 0;
    	while (arr[i])
    		free(arr[i++]);
    	free(arr);
    }
    
    char	**ft_split(char const *s, char c)
    {
    	int		size;
    	char	**dst_arr;
    
      // 1. 필요한 공간의 크기를 구한다.
    	size = count_size(s, c);
      // 2. (필요한 공간 + 1)만큼 공간할당을 한다. (마지막 NULL 자리)
    	dst_arr = (char **)malloc(sizeof(char *) * (size + 1));
    	if (dst_arr == NULL)
    		return (NULL);
    	dst_arr[size] = NULL;
      // 3. 문자열을 split 해서 공간할당을 한 배열에 각각 담는다.0
    	if (split_str(dst_arr, s, c, ft_strlen(s)) == 0)
    	{
        // split한 문자열을 담을 공간할당에 실패하면 이 때까지 할당했던 공간을 모두 수거한다.
    		array_free(dst_arr);
    		return (NULL);
    	}
    	return (dst_arr);
    }
    ```
    
- Notes
    1. 문자열의 양 쪽 끝 문자가 delimiter 일수도, 일반 문자 일수도 있다.
        - `s = "abc&def&"`
        - `s = "abc&def"`
            - '\0'` 문자까지 반복문이 돌도록 해서, delimiter와 같은 케이스로 묶음으로써 해결
        - `s = "&abc&def"`
            - `flag`의 init을 통해 첫 글자가 delimiter인 경우 그냥 지나가도록 해결
    2. delimiter가 이어질 수도 있다.
        - `s = "abc&def&&abc"`
        - `flag` 를 둬서 (delimiter or 일반 문자)가 이어지는 경우는 그냥 지나가도록 해결
    3. 공간 할당 실패 시
        - 이 때까지 할당해줬던 모든 공간을 해제해야 한다.

### **`itoa()`**

- Prototype
    
    ```c
    char	*ft_itoa(int n);
    ```
    
- Parameters
    - `n`: 변환할 정수
        
        > The integer to convert.
        > 
- Return value
    - 정수를 표현할 문자열. 할당 실패 시 NULL
        
        > The string representing the integer. NULL if the allocation fails.
        > 
- External functions
    - `malloc`
- Description
    - `malloc()`을 이용하여 메모리를 할당하고, 인자로 받은 정수를 나타내는 문자열을 반환한다. 음수 또한 무조건 처리되어야 한다.
        
        > Allocates (with malloc()) and returns a string representing the integer received as an argument. Negative numbers must be handled.
        > 
- Solve
    
    ```c
    #include <stdlib.h>
    
    // 정수를 문자열로 변환할 때 필요한 문자열의 크기를 계산하는 함수 (null-terminating 문자 자리 포함)
    int	count_size_to_allocate(int n)
    {
    	int	cnt;
    
    	if (n == 0)
    		return (2);
    	cnt = 0;
      // 음수면 (- 부호) 자리 추가
    	if (n < 0)
    		cnt++;
    	while (n != 0)
    	{
    		n /= 10;
    		cnt++;
    	}
      // null-terminating 자리 추가
    	return (cnt + 1);
    }
    
    // 한 자리씩 (정수 -> 문자)로 변환하는 재귀함수
    // n이 0이 되면 더이상 재귀호출을 하지 않는다.
    // 음수를 나머지 연산하면 -> 음수값이 나온다.
    void	recursion_convert(char *str, int idx, int n)
    {
    	if (n < 0)
    	{
    		str[0] = '-';
    		recursion_convert(str, idx - 1, -(n / 10));
    		str[idx] = -(n % 10) + '0';
    	}
    	else if (n > 0)
    	{
    		recursion_convert(str, idx - 1, n / 10);
    		str[idx] = (n % 10) + '0';
    	}
    }
    
    char	*ft_itoa(int n)
    {
    	int		size;
    	char	*str;
    	
      // 1. 할당할 공간의 크기를 계산한다.
    	size = count_size_to_allocate(n);
      // 2. 공간을 할당하고 null-terminating 문자를 넣어준다.
    	str = (char *)malloc(sizeof(char) * size);
    	if (str == NULL)
    		return (NULL);
    	str[size - 1] = '\0';
      // exception handling
    	if (n == 0)
    	{
    		str[0] = '0';
    		return (str);
    	}
      // 3. 재귀로 한자리씩 변환한다. (정수 -> 문자)
    	recursion_convert(str, size - 2, n);
    	return (str);
    }
    ```
    

### **`strmapi()`**

- Prototype
    
    ```c
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
    ```
    
- Parameters
    - `s`: 함수를 적용할 문자열
        
        > The string on which to iterate.
        > 
    - `f`: 문자열의 각 문자에 적용할 함수
        
        > The function to apply to each character.
        > 
- Return value
    - 원본 문자열에서 함수 `f`를 성공적으로 적용하여 생성된 결과 문자열. 할당 실패시, NULL
        
        > The string created from the successive applications of f. Returns NULL if the allocation fails.
        > 
- External functions
    - `malloc`
- Description
    - 문자열 `s`의 각 문자에 함수 `f`를 적용하고, 해당 문자의 인덱스를 함수 `f`의 첫 번째 인자로 전달하여 `f`를 연속적으로 적용한 새로운 문자열을 생성한다. (`malloc()`)을 이용하여 메모리를 할당
        
        > Applies the function f to each character of the string s, and passing its index as first argument to create a new string (with malloc()) resulting from successive applications of f.
        > 
- Solve
    
    ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
    {
    	char	*dst;
    	int		i;
    
    	if (s == NULL || f == NULL)
    		return (NULL);
    	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    	if (dst == NULL)
    		return (NULL);
    	i = 0;
    	while (s[i])
    	{
    		dst[i] = f((unsigned int)i, s[i]);
    		i++;
    	}
    	dst[i] = '\0';
    	return (dst);
    }
    ```
    
- Notes
    1. 함수 포인터
        - `반환타입 (*함수포인터이름)(매개변수타입))`
        - 함수 포인터는 반환타입과 매개변수타입이 모두 일치해야 할당이 가능하다.
        - 함수 포인터 할당 ex)
            
            ```c
            #include <stdio.h>
            
            int	sum(int a, int b)
            {
            	return (a + b);  
            }
            
            int	main(void)
            {
              // 함수 포인터 선언
              int (*f_p)(int, int);
              
              // 함수 포인터에 함수 할당
              f_p = &sum;
              // 같은 의미 (함수이름 자체에도 함수의 주소가 저장되어 있다.)
              // f_p = sum;
              
              // 함수 포인터를 통한 함수 호출
              int num = f_p(10, 20);
             	printf("f_p(%d, %d) returns %d\n", 10, 20, num);
              return (0);
            }
            ```
            

### **`striteri()`**

- Prototype
    
    ```c
    void	ft_striteri(char *s, void (*f)(unsigned int, char *));
    ```
    
- Parameters
    - `s`: 함수를 적용할 문자열
        
        > The string on which to iterate.
        > 
    - `f`: 문자열의 각 문자에 적용할 함수
        
        > The function to apply to each character.
        > 
- Return value
    
    > None
    > 
- External functions
    
    > None
    > 
- Description
    - 인자로 전달된 문자열의 각 문자를 순회하며 함수 `f`를 적용하고, 해당 문자의 인덱스를 함수 `f`의 첫 번째 인자로 전달한다. 각 문자는 주소를 통해 `f` 함수에 전달되어 필요한 경우 수정된다.
        
        > Applies the function f to each character of the string passed as argument, passing its index as first argument. Each character is passed by address to f to the be modified if necessary.
        > 
- Solve
    
    ```c
    void	ft_striteri(char *s, void (*f)(unsigned int, char *))
    {
    	unsigned int	i;
    
    	i = 0;
    	while (s[i])
    	{
    		f(i, &s[i]);
    		i++;
    	}
    }
    ```
    

### **`putchar_fd()`**

- Prototype
    
    ```c
    void	ft_putchar_fd(char *c, int fd);
    ```
    
- Parameters
    - `c`: 출력할 문자
        
        > The character to output.
        > 
    - `fd`: 값이 쓰여질 파일 식별자 (file descriptor)
        
        > The file descriptor on which to write.
        > 
- Return value
    - None
- External functions
    - `write`
- Description
    - 제공받은 파일 식별자에 문자 `c`를 출력한다.
        
        > Outputs the character c to the given file descriptor.
        > 
- Solve
    
    ```c
    #include <unistd.h>
    
    void	ft_putchar_fd(char c, int fd)
    {
    	if (fd < 0)
    		return ;
    	write(fd, &c, 1);
    }
    ```
    
- Notes
    1. `write` 함수는 무엇인가?
        
        ```c
        #include <unistd.h>
        ssize_t	write(int fd, const void *buf, size_t count);
        ```
        
        - `write()`는 `buf`에서 시작하는 버퍼에서 file descriptor `fd`가 참조하는 파일에 `count` 바이트까지 쓰는 함수
    2. `fd` 파일 디스크립터?
        - 리눅스와 유닉스에서는 시스템을 전부 파일로 처리하여 관리한다. 시스템에서 프로세스가 파일에 접근하기 위한 방법으로 파일 디스크립터(File Descriptor)라는 핸들이 필요하다.
        - 해당 파일을 open할 때 (해당 파일에 접근할 때) 파일 디스크립터는 0부터 N까지 즉, 음수가 아닌 0부터 차례대로 숫자를 부여받는다.
        - 0, 1, 2는 프로세스가 메모리에서 실행을 시작할 때 기본적으로 할당되는 파일 디스크립터이다.
            - 0: 표준 입력(stdin)
            - 1: 표준 출력(stdout)
            - 2: 표준 오류(stderr)
        - 그러므로 우리가 생성하는 파일 디스크립터들은 3번부터 차례대로 할당받게 된다. 쉽게 생각하면, 파일 디스크립터는 파일을 다루기 위해서 해당파일의 주소를 참조하여 접근하는 형태라고 생각하면 된다.
        - [https://wonillism.tistory.com/166](https://wonillism.tistory.com/166)
    3. `ssize_t`는 무엇인가?
        - signed size_t
        - 가장 큰 사이즈를 담을 수 있는 signed 데이터 타입 (음수를 포함하기 위해 사용)
            - 32bit 머신 -> signed int
            - 64bit 머신 -> signed long long

### **`putstr_fd()`**

- Prototype
    
    ```c
    void	ft_putstr_fd(char *s, int fd);
    ```
    
- Parameters
    - `s`: 출력할 문자열
        
        > The string to output.
        > 
    - `fd`: 값이 쓰여질 파일 식별자
        
        > The file descriptor on which to write.
        > 
- Return value
    
    > None
    > 
- External functions
    - `write`
- Description
    - 제공받은 파일 식별자에 문자열 `s`를 출력한다.
        
        > Outputs the string s to the given file descriptor.
        > 
- Solve
    
    ```c
    #include <unistd.h>
    #include "libft.h"
    
    void	ft_putstr_fd(char *s, int fd)
    {
    	if (s == NULL || fd < 0)
    		return ;
    	write(fd, s, ft_strlen(s));
    }
    ```
    

### **`putendl_fd()`**

- Prototype
    
    ```c
    void	ft_putendl_fd(char *s, int fd);
    ```
    
- Parameters
    - `s`: 출력할 문자열
        
        > The string to output.
        > 
    - `fd`: 값이 쓰여질 파일 식별자
        
        > The file descriptor on which to write.
        > 
- Return value
    
    > None
    > 
- External functions
    - `write`
- Description
    - 제공받은 파일 식별자에 문자열 `s`를 출력하고, 개행을 출력한다.
        
        > Outputs the string s to the given file descriptor followed by a newline.
        > 
- Solve
    
    ```c
    #include <unistd.h>
    #include "libft.h"
    
    void	ft_putendl_fd(char *s, int fd)
    {
    	if (s == NULL || fd < 0)
    		return ;
    	write(fd, s, ft_strlen(s));
    	write(fd, "\n", 1);
    }
    ```
    

### **`putnbr_fd()`**

- Prototype
    
    ```c
    void	putnbr_fd(int n, int fd);
    ```
    
- Parameters
    - `n`: 출력할 정수
        
        > The string to output.
        > 
    - `fd`: 값이 쓰여질 파일 식별자
        
        > The file descriptor on which to write.
        > 
- Return value
    
    > None
    > 
- External functions
    - `write`
- Description
    - 제공받은 파일 식별자에 정수 `n`을 출력한다.
        
        > Outputs the integer n to the given file descriptor.
        > 
- Solve
    
    ```c
    #include <unistd.h>
    
    void	recursion_write(int n, int fd)
    {
    	if (n > 0)
    	{
    		recursion_write(n / 10, fd);
    		write(fd, &"0123456789"[n % 10], 1);
    	}
    	else if (n < 0)
    	{
    		write(fd, "-", 1);
    		recursion_write(-(n / 10), fd);
    		write(fd, &"0123456789"[-(n % 10)], 1);
    	}
    }
    
    void	ft_putnbr_fd(int n, int fd)
    {
    	if (fd < 0)
    		return ;
    	if (n == 0)
    		write(fd, "0", 1);
    	else
    		recursion_write(n, fd);
    }
    ```