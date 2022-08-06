# Bonus part

# `make bonus`

- `make bonus`는 `libft.a` 라이브러리에 보너스 함수들을 추가한다.
    - `make bonus` 의 리링크(relink)를 방지하기 위해 `ar` 커맨더의 `u` 플래그를 사용했다.
        - 파일을 업데이트 한다. -r 옵션과 함께 사용하면 디스크 파일(오브젝트 파일)의 수정 시간이 아카이브의 파일보다 최신인 경우에만 아카이브의 파일이 교체된다.
        
        > Update files. When used with the -r option, files in the archive will be replaced only if the disk file has a newer modification time than the file in the archive.
        > 

```c
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

BON_SRCS = ft_lstnew.c \
		   ft_lstadd_front.c \
		   ft_lstsize.c \
		   ft_lstlast.c \
		   ft_lstadd_back.c \
		   ft_lstdelone.c \
		   ft_lstclear.c \
		   ft_lstiter.c \
		   ft_lstmap.c
BON_OBJS = $(BON_SRCS:.c=.o)

AR = ar
ARFLAGS = rcs
BON_ARFLAGS = $(ARFLAGS)u
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus
all : $(NAME)
clean :
	rm -f $(OBJS) $(BON_OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
bonus : all $(BON_OBJS)
	$(AR) $(BON_ARFLAGS) $(NAME) $(BON_OBJS)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

---

# List structure

```c
typedef struct s_list
{
  void	*content;
  struct s_list	*next;
}	t_list;
```

- `content`: 요소에 포함된 데이터. `void *`를 통해 어떠한 자료형의 값도 담을 수 있다.
    
    > The data contained in the element. The void * allows to store any kind of data.
    > 
- `next`: 다음 요소의 주소값. 만약 해당 요소가 마지막 요소라면, `NULL`을 가리킨다.
    
    > The next element's address or NULL if it's the last element.
    > 

---

# functions

### **`ft_lstnew()`**

- Prototype
    
    ```c
    t_list	*ft_lstnew(void *content);
    ```
    
- Parameters
    - `content`: 새로운 요소에 들어갈 content
        
        > The content to create the node with.
        > 
- Return value
    
    > The new node
    > 
- External functions
    - `malloc`
- Description
    - `malloc()`을 통해 메모리를 할당하고 새로운 요소를 반환한다. 요소 내의 변수 `content`는 인자로 받아온 `content`로 초기화되어야 한다. 요소 내의 변수 `next`는 `NULL`로 초기화되어어야 한다.
        
        > Allocates (with malloc()) and returns a new element. The variable content is initialized with the value of the parameter content. The variable next is initialized to NULL.
        > 
- Solve
    
    ```c
    #include "libft.h"
    #include <stdlib.h>
    
    t_list	*ft_lstnew(void *content)
    {
    	t_list	*new;
    
    	new = (t_list *)malloc(sizeof(t_list));
    	if (new == NULL)
    		return (NULL);
    	new->content = content;
    	new->next = NULL;
    	return (new);
    }
    ```
    

### **`ft_lstadd_front()`**

- Prototype
    
    ```c
    void	ft_lstadd_front(t_list **lst, t_list *new);
    ```
    
- Parameters
    - `lst`: 리스트의 맨 앞에 위치한 요소의 주소
        
        > The address of pointer to the first link of a list.
        > 
    - `new`: 리스트에 추가할 요소
        
        > The address of a pointer to the node to be added to the list.
        > 
- Return value
    
    > None
    > 
- External functions
    - None
- Description
    - 요소 `new`를 리스트의 맨 앞에 추가한다.
        
        > Adds the node new at the beginning of the list.
        > 
- Solve
    
    ```c
    #include "libft.h"
    
    void	ft_lstadd_front(t_list **lst, t_list *new)
    {
    	t_list	*old_head;
    
    	if (lst == NULL || new == NULL)
    		return ;
    	old_head = *lst;
    	*lst = new;
    	new->next = old_head;
    }
    ```
    
- Notes
    1. 예외사항에 `lst == NULL`을 넣지 않은 경우
        - 빈 리스트로 들어왔을 떄, `new` 노드만 하나 있는 리스트로 만들어주기 위함.
        - `lst`가 NULL인 것은 빈 리스트가 아님

### **`ft_lstsize()`**

- Prototype
    
    ```c
    int	ft_lstsize(t_list *lst);
    ```
    
- Parameters
    - `lst`: 리스트의 맨 앞에 위치한 요소
        
        > The beggining of the list.
        > 
- Return value
    
    > The length of the list.
    > 
- External functions
    - None
- Description
    - 리스트에 포함된 요소의 개소를 센다.
        
        > Counts the number of nodes in a list.
        > 
- Solve
    
    ```c
    #include "libft.h"
    
    int	ft_lstsize(t_list *lst)
    {
    	int	cnt;
    
    	cnt = 0;
    	while (lst)
    	{
    		cnt++;
    		lst = lst->next;
    	}
    	return (cnt);
    }
    ```
    

### **`ft_lstlast()`**

- Prototype
    
    ```c
    t_list	*ft_lstlast(t_list *lst);
    ```
    
- Parameters
    - `lst`: 리스트의 맨 앞에 위치한 요소
        
        > The beggining of the list.
        > 
- Return value
    
    > Last node of the list.
    > 
- External functions
    - None
- Description
    - 리스트의 마지막에 위치한 요소를 반환한다.
        
        > Returns the last node of the list.
        > 
- Solve
    
    ```c
    #include "libft.h"
    
    t_list	*ft_lstlast(t_list *lst)
    {
    	if (lst == NULL)
    		return (NULL);
    	while (lst->next)
    		lst = lst->next;
    	return (lst);
    }
    ```
    

### **`ft_lstadd_back()`**

- Prototype
    
    ```c
    void	ft_lstadd_back(t_list **lst, t_list *new);
    ```
    
- Parameters
    - `lst`: 리스트의 맨 앞에 위치한 요소의 포인터
        
        > The address of a pointer to the first link of a list.
        > 
    - `new`: 리스트의 맨 끝에 추가할 요소
        
        > The address of a pointer to the node to be added to the list.
        > 
- Return value
    
    > None
    > 
- External functions
    - None
- Description
    - 요소 `new`를 리스트의 맨 뒤에 추가한다.
        
        > Adds the node new at the end of the list.
        > 
- Solve
    
    ```c
    #include "libft.h"
    
    void	ft_lstadd_back(t_list **lst, t_list *new)
    {
    	t_list	*node;
    
    	if (lst == NULL || new == NULL)
    		return ;
      // *lst가 NULL이라면 -> 빈 리스트이다.
    	if (*lst == NULL)
    		*lst = new;
    	else
    	{
    		node = *lst;
    		while (node->next)
    			node = node->next;
    		node->next = new;
    	}
    }
    ```
    
- Notes
    1. 예외처리: `lst == NULL`
        - 빈 리스트가 들어왔을 떄, `new` 노드만 하나 있는 리스트로 만들어준다.
        - `lst`가 NULL인 것은 빈 리스트가 아님!

### **`ft_lstdelone()`**

- Prototype
    
    ```c
    void	ft_lstdelone(t_list *lst, void (*del)(void *));
    ```
    
- Parameters
    - `lst`: 공간할당을 해제할 요소
        
        > The node to free.
        > 
    - `del`: 요소의 content 삭제에 사용되는 함수 포인터
        
        > The address of the function used to delete the content.
        > 
- Return value
    
    > None
    > 
- External functions
    - `free`
- Description
    - 첫 번째 인자로 받은 요소의 `content`를 두 번째 인자로 받은 `del` 함수 포인터를 이용해 해제하고, 요소 자체의 메모리를 해제한다. `next` 포인터는 해제하면 안된다.
        
        > Takes as a parameter a node and frees the memory of the node's content using the function del given as a parameter and free the node. The memory of next must not be freed.
        > 
- Solve
    
    ```c
    #include "libft.h"
    #include <stdlib.h>
    
    void	ft_lstdelone(t_list *lst, void (*del)(void *))
    {
    	if (lst == NULL || del == NULL)
    		return ;
    	del(lst->content);
    	free(lst);
    }
    ```
    

### **`ft_lstclear()`**

- Prototype
    
    ```c
    void	ft_lstclear(t_list **lst, void (*del)(void *));
    ```
    
- Parameters
    - `lst`: 삭제할 요소의 포인터
        
        > The address of a pointer to a node.
        > 
    - `del`: 요소의 content 삭제에 사용되는 함수 포인터
        
        > The address of the function used to delete the content of the node.
        > 
- Return value
    
    > None
    > 
- External functions
    - `free`
- Description
    - 함수 `del`과 `free`를 이용하여 인자값으로 받은 요소와 그 뒤에 따라오는 리스트의 모든 요소들을 삭제하고 해제한다. 최종적으로, 리스트의 포인터는 NULL로 설정되어야 한다.
        
        > Deletes and frees the given node and every successor of that node, using the function del and free. Finally, the pointer to the list must be set to NULL.
        > 
- Solve
    
    ```c
    #include "libft.h"
    
    void	ft_lstclear(t_list **lst, void (*del)(void *))
    {
    	t_list	*cur;
    	t_list	*next;
    
    	cur = *lst;
    	while (node)
    	{
    		next = cur->next;
    		ft_lstdelone(cur, del);
    		cur = next;
    	}
    	*lst = NULL;
    }
    ```
    

### **`ft_lstiter()`**

- Prototype
    
    ```c
    void	ft_lstiter(t_list *lst, void (*f)(void *));
    ```
    
- Parameters
    - `lst`: 리스트상의 요소의 주소
        
        > The address of a pointer to a node.
        > 
    - `f`: 리스트 내에서 반복 적용될 함수 포인터
        
        > The address of the function used to iterate on the list.
        > 
- Return value
    
    > None
    > 
- External functions
    - None
- Description
    - 리스트 `lst`를 순회하며, 리스트에 포함된 모든 요소들의 content에 함수 `f`를 반복적으로 적용시킨다.
        
        > Iterates the list lst and applies the function f on the content of each node.
        > 
- Solve
    
    ```c
    #include "libft.h"
    
    void	ft_lstiter(t_list *lst, void (*f)(void *))
    {
      // lst == NULL 은 예외처리할 필요가 없지만, 보기편하려고 넣었다. (lst == NULL 이면 자동으로 반복문을 지나가기 때문)
    	if (lst == NULL || f == NULL)
    		return ;
    	while (lst)
    	{
    		f(lst->content);
    		lst = lst->next;
    	}
    }
    ```
    

### **`ft_lstmap()`**

- Prototype
    
    ```c
    t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
    ```
    
- Parameters
    - `lst`: 리스트상의 요소
        
        > The address of a pointer to a node.
        > 
    - `f`: 리스트 내에서 반복 적용될 함수 포인터
        
        > The address of the function used to iterate on the list.
        > 
    - `del`: 필요할 경우, 요소의 content를 삭제하는 데에 사용되는 함수
        
        > the address of the function used to delete the content of a node if needed.
        > 
- Return value
    
    > The new List. NULL if the allocation fails.
    > 
- External functions
    - `malloc`, `free`
- Description
    - 리스트 `lst`의 요소들을 순회하며 각 요소의 content에 함수 `f`를 적용한다. 또한 함수. `f`를 연속 적용시킨 결과물들을 content로 담은 새로운 리스트를 생성한다. `del` 함수들은 필요 시 각 요소의 content를 삭제하는 데 사용된다.
        
        > Iterates the list lst and applies the function f on the content of each node. Creates a new list resulting of the successive applications of the function f. The del function is used to delete the content of a node if needed.
        > 
- Solve
    
    ```c
    #include "libft.h"
    #include <stdlib.h>
    
    void	clear_just_nodes(t_list *lst)
    {
    	t_list	*tmp;
    
    	while (lst)
    	{
    		tmp = lst->next;
    		free(lst);
    		lst = tmp;
    	}
    }
    
    t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
    {
    	t_list	*head;
    	t_list	*node;
    
    	if (lst == NULL || f == NULL)
    		return (NULL);
    	head = ft_lstnew(f(lst->content));
    	if (head == NULL)
    		return (NULL);
    	node = head;
    	while (lst->next)
    	{
    		node->next = ft_lstnew(f(lst->next->content));
    		if (node->next == NULL)
    		{
    			if (del)
    				ft_lstclear(&head, del);
    			else
    				clear_just_nodes(head);
    			return (NULL);
    		}
    		node = node->next;
    		lst = lst->next;
    	}
    	return (head);
    }
    ```
    
- Notes
    1. `del`
        - `del`함수가 `NULL`인 상태에서 node 생성에 실패했을 때, 이 때까지 생성했던 모든 node들을 `free`해줘야 하나?
            - 해줘야 한다면
                - 각각의 node들의 content로 인한 메모리 누수는?
            - 안해줘야 한다면
                - node들로 인한 메모리 누수는?
            - 사용자가 함수를 호출할 때, `del`을 `NULL`로 준 이유를 알 수 없다.
                1. content는 해제할 필요 없고, node들만 공간해제 해줘.
                2. 아 content도 해제해야 맞긴한데 까먹었다.
            - 어차피 내가 쓸 라이브러리니까, 1번으로 가정하고 해결하기로 했다.