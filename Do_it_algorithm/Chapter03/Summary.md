# 03. 자료구조

## 03-1. 배열과 리스트 그리고 벡터

### 배열과 리스트의 핵심 이론

#### 배열

메모리의 연속 공간에 값이 채워져 있는 형태의 자료구조이다. 특징은 다음과 같다.

- 인덱스를 사용하여 값에 바로 접근할 수 있다.
- 새로운 값을 삽입하거나 특정 인덱스에 있는 값을 삭제하기 어렵다. 값을 삽입하거나 삭제하려면 해당 인덱스 주변에 있는 값을 이동시키는 과정이 필요하다.
- 배열의 크기는 선언할 때 지정할 수 있으며, 한 번 선언하면 크기를 늘리거나 줄일 수 없다.
- 구조가 간단하므로 코딩 테스트에서 많이 사용한다.

#### 리스트

값과 포인터를 묶은 노드라는 것을 포인터로 연결한 자료구조이다. 특징은 다음과 같다.

- 인덱스가 없으므로 값에 접근하려면 Head 포인터부터 순서대로 접근해야 한다. 그러므로 값에 접근하는 속도가 느리다.
- 포인터로 연결되어 있으므로 데이터를 삽입하거나 삭제하는 연산 속도가 빠르다.
- 선언할 때 크기를 별도로 지정하지 않아도 된다. 즉, 리스트의 크기는 정해져 있지 않으며 크기가 변하기 쉬운 데이터를 다룰 때 적절하다.
- 포인터를 저장할 공간이 필요하므로 배열보다 구조가 복잡하다.

#### 벡터

`vector`는 C++ 표준 라이브러리(Standard Template Library)에 있는 자료구조 컨테이너 중 하나로, 기존의 배열과 같은 특징을 가지면서 배열의 단점을 보완한 동적 배열의 형태이다. 특징은 다음과 같다.

- 동적으로 원소를 추가할 수 있다. 즉, 크기가 자동으로 늘어난다.
- 맨 마지막 위치에 데이터를 삽입하거나 삭제할 때는 문제가 없지만 중간 데이터의 삽입, 삭제 연산은 배열과 같은 메커니즘으로 동작한다.
- 배열과 마찬가지로 인덱스를 이용하여 각 데이터에 직접 접근할 수 있다.

**벡터 사용법**
```
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    // declaration
    vector<int> A;

    // insertion
    A.push_back(1);
    A.insert(A.begin(), 7);
    A.insert(A.begin() + 2, 10);

    // value change
    A[4] = -5;

    // deletion
    A.pop_back();
    A.erase(A.begin() + 3);
    A.clear();

    // information extraction
    A.size();
    A.front();
    A.back();
    A[3];
    A.at(5);
    A.begin();
    A.end();
}
```

## 03-2. 구간 합

구간 합은 합 배열을 이용하여 시간 복잡도를 줄이기 위해 사용하는 특수한 목적의 알고리즘이다.

### 구간 합의 핵심 이론

먼저, 배열 A가 있을 때 합 배열 S는 다음과 같이 정의된다.

```
S[i] = A[0] + A[1] + A[2] + ... + A[i-1] + A[i]
```

합 배열은 다음과 같은 간단한 공식으로 만들 수 있다.

```
S[i] = S[i-1] + A[i]
```

이 합 배열로 구간 합도 쉽게 구할 수 있다. 예를 들어 i에서 j까지의 구간 합을 구하는 공식은 다음과 같다.

```
S[j] - S[i-1]
```

## 03-3. 투 포인터

투 포인터는 2개의 포인터로 알고리즘의 시간 복잡도를 최적화한다.

투 포인터의 이동 원칙은 다음과 같다.

- A[i] + A[j] > M: j--;
- A[i] + A[j] < M: i++;
- A[i] + A[j] == M: count++; i++; j--;

## 03-4. 슬라이딩 윈도우

슬라이딩 윈도우는 2개의 포인터로 범위(window)를 지정한 다음 범위를 유지한 채로 이동(sliding)하면서 문제를 해결한다.

## 03-5. 스택과 큐

### 스택과 큐의 핵심 이론

#### 스택

스택(Stack)은 후입선출(LIFO: Last-In First-Out)로 삽입과 삭제 연산이 이루어진다. 후입선출은 삽입과 삭제가 한 쪽에서만 일어난다는 특징이 있다.

스택 용어는 다음과 같은 것들이 있다.

**위치**
- **top**: 삽입과 삭제가 일어나는 위치이다.

**연산**
- **push**: top 위치에 새로운 데이터를 삽입하는 연산이다.
- **pop**: top 위치에 현재 있는 데이터를 삭제하고 확인하는 연산이다.
- **top**: top 위치에 현재 있는 데이터를 단순 확인하는 연산이다.

스택은 깊이 우선 탐색(DFS: Depth First Search), 백트래킹 종류의 문제에 효과적이다. 후입선출의 개념 자체가 재귀 함수 알고리즘 원리와 일맥상통하기 때문이다.

#### 큐

큐는 선입선출(FIFO: First-In First-Out)로 삽입과 삭제 연산이 이루어진다. 그러므로 삽입과 삭제가 양방향에서 이루어진다.

큐 용어는 다음과 같은 것들이 있다.

**위치**
- **back**: 큐에서 가장 끝 데이터를 가리키는 영역이다.
- **front**: 큐에서 가장 앞의 데이터를 가리키는 영역이다.

**연산**
- **push**: back 부분에 새로운 데이터를 삽입하는 연산이다.
- **pop**: front 부분에 있는 데이터를 삭제하고 확인하는 연산이다.

큐는 너비 우선 탐색(BFS: Breadth First Search) 문제에 자주 사용된다.