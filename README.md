# 42SEOUL

## 0. libft
- 첫 과제로, C라이브러리 함수들과 똑같이 동작하도록 나만의 함수 라이브러리를 만들기.
- `atoi()`, `itoa()`, `memcpy()`, `memmove()`, `strdup()`, `strcat()`, `strcmp()`등. 총 43개(보너스 포함).
<details>
<summary>구현 함수 정리</summary>
<table>
  <thead>
    <th>번호</th>
    <th>함수 이름</th>
    <th>함수 기능</th>
  </thead>
  <tbody>
    <tr><td>1</td><td>int ft_atoi(const char *str)</td><td>char *로 입력된 숫자를 int로 바꿔주는 함수</td></tr>
    <tr><td>2</td><td>void ft_bzero(void *s, size_t n)</td><td>n만큼 0으로 초기화하는 함수</td></tr>
    <tr><td>3</td><td>void *ft_calloc(size_t count, size_t size)</td><td>malloc하고 0으로 초기화하는 함수</td></tr>
    <tr><td>4</td><td>int ft_isalnum(int c)</td><td>알파벳 또는 숫자인지 확인하는 함수</td></tr>
    <tr><td>5</td><td>int ft_isalpha(int c)</td><td>알파벳인지 확인하는 함수</td></tr>
    <tr><td>6</td><td>int ft_isascii(int c)</td><td>아스키문자인지 확인하는 함수</td></tr>
    <tr><td>7</td><td>int ft_isdigit(int c)</td><td>숫자인지 확인하는 함수</td></tr>
    <tr><td>8</td><td>int ft_isprint(char c)</td><td>printable 문자인지 확인하는 함수</td></tr>
    <tr><td>9</td><td>char *ft_itoa(int n)</td><td>int자료형 정수를 char *로 바꿔주는 함수</td></tr>
    <tr><td>10</td><td>void	ft_lstadd_back(t_list **lst, t_list *new)</td><td>연결리스트 마지막 노드 다음에 새로운 노드 연결해주는 함수</td></tr>
    <tr><td>11</td><td>void	ft_lstadd_front(t_list **lst, t_list *new)</td><td>연결리스트 맨 앞에 새로운 노드 추가하는 함수</td></tr>
    <tr><td>12</td><td>void ft_lstclear(t_list **lst, void (*del)(void *))</td><td>연결리스트 삭제해주는 함수</td></tr>
    <tr><td>13</td><td>void	ft_lstdelone(t_list *lst, void (*del)(void *))</td><td>연결리스트에서 특정노드 삭제하는 함수</td></tr>
    <tr><td>14</td><td>void	ft_lstiter(t_list *lst, void (*f)(void *))</td><td>연결리스트 각 노드의 content를 f함수에 적용하는 함수</td></tr>
    <tr><td>15</td><td>t_list *ft_lstlast(t_list *lst)</td><td>연결리스트 마지막 노드 리턴하는 함수</td></tr>
    <tr><td>16</td><td>t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))</td><td>함수 f에 연결리스트의 각 노드의 content를 넣어서 새로운 연결리스트를 만들어 주는 함수</td></tr>
    <tr><td>17</td><td>t_list	*ft_lstnew(void *content)</td><td>새로운 연결리스트 노드를 생성하는 함수</td></tr>
    <tr><td>18</td><td>int ft_lstsize(t_list *lst)</td><td>연결리스트로 몇개의 노드가 연결되어있는지 계산하는 함수</td></tr>
    <tr><td>19</td><td>void *ft_memchr(const void *s, int c, size_t n)</td><td>문자열 s의 n byte내, c와 같은 값을 찾는 함수(가장 처음 만나는 c)</td></tr>
    <tr><td>20</td><td>int ft_memcmp(const void *s1, const void *s2, size_t n)</td><td>문자열 s1과 문자열 s2를 n만큼 비교하는 함수</td></tr>
    <tr><td>21</td><td>void *ft_memcpy(void *dst, void *src, size_t n)</td><td>n만큼 dst에 src를 복사하는 함수(overlap 기능 정의x)</td></tr>
    <tr><td>22</td><td>void *ft_memmove(void *dst, const void *src, size_t len)</td><td>n만큼 dst에 src를 복사하는 함수(overlap가능)</td></tr>
    <tr><td>23</td><td>void *ft_memset(void *b, int c, size_t len)</td><td>문자열 b를 len만큼 c로 만드는 함수</td></tr>
    <tr><td>24</td><td>void	ft_putchar_fd(char c, int fd)</td><td>문자 출력하는 함수</td></tr>
    <tr><td>25</td><td>void	ft_putendl_fd(char *s, int fd)</td><td>문자열 출력하고 개행까지 하는 함수</td></tr>
    <tr><td>26</td><td>void	ft_putnbr_fd(int n, int fd)</td><td>정수 출력하는 함수</td></tr>
    <tr><td>27</td><td>void ft_putstr_fd(char *s, int fd)</td><td>문자열 출력하는 함수</td></tr>
    <tr><td>28</td><td>char **ft_split(char const *s, char c)</td><td>문자열 s에서 c를 기준으로 나누어 char **에 넣어주는 함수</td></tr>
    <tr><td>29</td><td>char *ft_strchr(const char *s, int c)</td><td>문자열 s에서 가장 먼저 만나는 c를 찾아주는 함수</td></tr>
    <tr><td>30</td><td>char *ft_strdup(const char *s1)</td><td>malloc해서 s1 복사하는 함수</td></tr>
    <tr><td>31</td><td>void	ft_striteri(char *s, void (*f)(unsigned int, char*))</td><td>포인터로 받은 함수에다가 문자열 s하나씩 집어넣는 함수</td></tr>
    <tr><td>32</td><td>char	*ft_strjoin(char const *s1, char const *s2)</td><td>문자열 s1에 문자열 s2 붙여주는 함수</td></tr>
    <tr><td>33</td><td>size_t	strlcat(char *dst, const char *src, size_t dstsize)</td><td>dst 문자열의 끝에 src 문자열을 최대 dstsize - 1만큼 붙이고, 최종 문자열의 길이를 반환하는 함수</td></tr>
    <tr><td>34</td><td>size_t ft_strlcpy(char *dst, const char *src, size_t datasize)</td><td>datasize만큼 dst에 src 복사하는 함수</td></tr>
    <tr><td>35</td><td>size_t ft_strlen(const char *s)</td><td>문자열의 길이 구해주는 함수</td></tr>
    <tr><td>36</td><td>char *ft_strmapi(char const *s, char (*f)(unsigned int, char))</td><td>함수 포인터로 받은 함수에다가 문자열 s의 문자 하나하나를 넣어서 결과값을 새로운 문자열에 저장하고 리턴해주는 함수</td></tr>
    <tr><td>37</td><td>int ft_strncmp(const char *s1, const char *s2, size_t n)</td><td>n만큼 문자열 s1와 문자열 s2를 비교하는 함수</td></tr>
    <tr><td>38</td><td>char *ft_strnstr(const char *haystack, const char *needle, size_t len)</td><td>문자열 haystack의 len byte내에서 문자열 needle을 찾아주는 함수</td></tr>
    <tr><td>39</td><td>char *ft_strrchr(const char *s, int c)</td><td>문자열 s에서 가장 마지막으로 만나는 문자 c의 위치를 찾아주는 함수</td></tr>
    <tr><td>40</td><td>char *ft_strtrim(char const *s1, char const *set)</td><td>s1 문자열에서 set에 포함된 문자들을 양 끝에서 제거한 새로운 문자열을 반환하는 함수</td></tr>
    <tr><td>41</td><td>char	*ft_substr(char const *s, unsigned int start, size_t len)</td><td>start위치부터 문자열 s의 len byte만큼 새로운 문자열에 저장하는 함수</td></tr>
    <tr><td>42</td><td>int ft_tolower(int c)</td><td>대문자를 소문자로 바꿔주는 함수</td></tr>
    <tr><td>43</td><td>int ft_toupper(int c)</td><td>소문자를 대문자로 바꿔주는 함수</td></tr>
  </tbody>
</table>
</details>

## 1-1. get_next_line
- 특정 파일을 받아서 해당 파일을 읽어오는데, 개행`\n`을 만나기 전까지만 출력하는 함수 만들기
- 정적변수를 사용하여 다시 호출하면 그 다음 공백까지가 출력되도록 만든다.

## 1-2. ft_printf
- 가변인자와 함수를 사용하여, printf() 직접 구현해보기.

## 1-3. born2beroot
- virtualbox를 사용하여, 가상머신을 생성하고 CLI환경에서 OS설치, ufw설정, ssh서비스 실행, sudo설정, monitoring.sh작성등 환경을 세팅해보기.

## 2-1. pushswap
- 스택A와 스택B 2개를 가지고 명령어를 최대한 적게 사용하여 입력받은 인자를 정렬하기.
![push_swap](https://github.com/user-attachments/assets/b31c0e4b-2a84-4317-8dee-4386bdc0ca6b)

## 2-2. so_long
- 첫 그래픽 과제. map의 유효성을 확인하고, mlx라이브러리를 사용하여 간단한 게임 만들기.
![so_long](https://github.com/user-attachments/assets/4b6a0f31-d3bf-4587-a13a-5c1768037173)

## 2-3. minitalk
- signal을 이용해 데이터를 주고받는 작은 프로그램 작성하기.
![minitalk](https://github.com/user-attachments/assets/af38c310-11e9-4362-bda6-c3594000a928)

## 3-1. minishell
- bash shell과 동일하게 동작하는 나만의 shell만들기.

## 3-2. philosophers
- 유명한 [식사하는 철학자 문제](https://namu.wiki/w/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94%20%EC%B2%A0%ED%95%99%EC%9E%90%20%EB%AC%B8%EC%A0%9C) 해결하기. pthread.h를 사용하여 멀티 쓰레드환경을 만들어 보고, mutex로 decdlock을 해결해보기.

### 철학자들이 사는 경우
![philo-live](https://github.com/user-attachments/assets/b34a0ed5-f617-4701-b404-1a9b7aa800f4)
<details>
<summary>philo가 짝수일때</summary>
<div>
<img src="https://github.com/user-attachments/assets/245325da-2f11-4ad6-ac83-36619de588a6" alt="philo 짝수">
</div>
</details>
<details>
<summary>philo가 홀수일때</summary>
<div>
<img src="https://github.com/user-attachments/assets/e3c0b055-ebd3-42e8-aa28-87b56260eb93" alt="philo 홀수">
</div>
</details>

### 철학자가 죽는 경우
![philo-die](https://github.com/user-attachments/assets/17a8cd98-a3bd-4eb4-b990-9ba597484b5b)

## 4-1. cub3d
- [레이캐스팅](https://lodev.org/cgtutor/raycasting.html)을 이용하여 1인칭 시점의 미로를 구현하기
![cub3d](https://github.com/user-attachments/assets/2b2d64b9-a944-4438-978a-eb10f6ea7e91)

## 4-2. cpp module
- 첫 C++과제. C++문법과 객체지향개념을 배울 수 있다.
