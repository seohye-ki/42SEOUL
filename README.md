# 42SEOUL

## 0. libft
- 첫 과제로, C라이브러리 함수들과 똑같이 동작하도록 나만의 함수 라이브러리를 만들기.
- `atoi()`, `itoa()`, `memcpy()`, `memmove()`, `strdup()`, `strcat()`, `strcmp()`등. 총 43개(보너스 포함).

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

## 4-2. cpp module
- 첫 C++과제. C++문법과 객체지향개념을 배울 수 있다.
