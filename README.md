# Study for Interview

---

## Table of Contents

- [Algorithm](#algorithm)
- [Data Structure](#data-structure)
- [Programming Language](#programming-language)
- [Database](#database)
- [Network](#network)
- [Operating System](#operating-system)

---

## Algorithm


---

## Data Structure


---

## Programming Language
- Javascript
    - Script 언어이므로 interpreter에 의해 실행된다.
    - Object 기반의 언어이며 Single Thread이다.
    


---

## Database


---

## Network

### TCP / UDP 차이점
- TCP(Transmission Control Protocol)
    - TCP는 신뢰성있는 데이터 전송을 지원하는 연결지향형 프로토콜이다. 연결지향형인 TCP는 3-way handshaking이라는 과정을 통해 연결 후 통신을 시작한다.
    - 흐름제어(보내는 측과 받는 측의 데이터 처리속도 차이를 조절)와 혼잡제어(네트워크 내의 패킷 수가 넘치게 증가하지 않도록 방지하는 것)를 지원하며 데이터의 순서를 보장한다.
    - TCP는 UDP에 비해 속도가 느리며, 대부분의 웹 HTTP 통신, 이메일, 파일전송에 사용된다.
- UDP(User Datagram Protocol)
    - UDP는 전송계층의 비연결형 프로토콜이다. TCP와 달리 연결 설정이 없으며, 혼잡제어를 하지 않기 때문에 TCP보다 빠르다.
    - 데이터 전송에 대한 보장을 하지 않기 때문에 패킷 손실이 발생할 수 있다. 이러한 특징 때문에 DNS, 멀티미디어에서 사용된다.
    - TCP와 같이 UDP도 헤더에 있는 Checksum 필드를 통해 최소한의 오류는 검출한다.
- Ref: [http://swalloow.tistory.com/77](http://swalloow.tistory.com/77)

---

## Operating System

### Process와 Thread의 차이점
- Process
    - 운영체제에서 실행 중인 프로그램에 대한 인스턴스를 프로세스라고 한다. 운영체제로부터 주소 공간, 파일, 메모리 등을 할당 받고, 독립적이기 때문에 메모리 영역을 다른 프로세스와 공유하지 않는다.
- Thread
    - 한 Process에서 동작되는 실행의 단위이다. 프로세스가 생성될 때 기본적으로 하나의 쓰레드가 생성되며 이를 메인 쓰레드라고 한다. 프로세스는 여러 개의 쓰레드를 가질 수 있으며, 각 쓰레드마다 별도의 스택이 있다.
    - 각 쓰레드는 같은 프로세스에 있는 다른 쓰레드와 독립적으로 돌아가지만, 기본적으로 쓰레드끼리는 파일 핸들이나 메모리 같은 자원들을 공유한다. 때문에 공유 자원에 대한 접근 처리를 제대로 하지않으면 데드락 같은 문제가 생길 수 있다.

### Multi Process, Multi Thread
- 두 개의 프로세스는 완전히 독립된 두 개의 프로그램 실행을 위해서 사용되기 때문에 Context Switching으로 인한 성능 저하가 발생한다.
- 쓰레드는 메모리 영역을 공유하기 때문에 Context Switching이 더 빠르다.

### Context Switching
- 하나의 프로세스가 CPU를 사용 중인 상태에서 다른 프로세스가 CPU를 사용하도록 하기 위해, 이전의 프로세스의 상태(문맥)를 보관하고 새로운 프로세스의 상태를 적재하는 작업을 말한다. 한 프로세스의 문맥은 그 프로세스의 PCB(Process Control Block)에 기록되어 있다
- 참고로 운영체제의 스케쥴러가 실행 단위로 사용하는 것은 프로세스가 아닌 쓰레드이다. 프로세스는 상태(Running, Ready, Blocked)을 지니지 않으며 상태를 지니는 것은 쓰레드이다.
- Context Switching 동안에는 작업을 수행할 수 없기 때문에, Context Swithching 시간은 일종의 오버헤드라고 할 수 있다.
- Ref: [http://hso9201.tistory.com/212](http://hso9201.tistory.com/212)

### Thread Synchronization(쓰레드 동기화)
- Monitor
    - Mutual Exclusion Lock(이하 자물쇠)으로 보호되는 루틴의 집합
    - 쓰레드는 이 자물쇠를 획득하기 전까지는 모니터에 속하는 루틴을 실행할 수 없다. 즉, 한 모니터 내에서는 한 쓰레드씩 실행되며 다른 쓰레드는 전부 지금 실행 중인 쓰레드에서 그 자물쇠를 놓아줄 때까지 기다려야 한다.
- Semaphore
    - 공유 자원을 보호하기 위한 자물쇠
    - 쓰레드에서 공유 자원을 사용하려면 이 자물쇠를 획득해야 하고, 자물쇠를 쥐고 있는 쓰레드에서 놓아주기 전까지는 다른 쓰레드는 기다려야 한다. 대기하고 있던 쓰레드가 자물쇠를 획득하게 되면, 공유 자원에 접근할 수 있다. 이를 Mutex 세마포어(가장 기본적)라고 한다.
    - Counting Semaphore: 정해진 숫자 n이 있어서 최대 n개의 쓰레드에서 동시에 자원에 접근할 수 있음
    - Event Semaphore: 어떤 이벤트가 발생했음을 대기 중인 쓰레드 중 하나 또는 모든 쓰레드에게 알림
- Monitor, Semaphore 모두 같은 목적이지만, 자물쇠의 획득과 해제를 모두 처리해주는 Monitor 쪽이 간단하게 쓰기 좋다. Semaphore의 경우, 각 쓰레드에서 획득한 자물쇠를 해제하는 작업을 일일히 챙겨야 한다.
- DeadLock
    - 두 쓰레드가 서로 상대방이 쥐고 있는 자물쇠가 풀리기만을 기다리고 있을 때 발생한다.

### Heap, Stack 차이점(메모리 구조)
- 운영체제는 프로그램을 실행시킬 때 메모리 공간을 할당하는데, 이 공간은 Stack, Heap, Data 영역으로 나뉜다.
- Data 영역
    - 전역 변수, Static 변수가 할당되는 영역
    - 프로그램의 시작과 동시에 할당되고, 프로그램이 종료되어야 메모리에서 소멸된다.
- Heap 영역
    - 동적으로 메모리를 할당할때 사용(프로그래머가 직접 관리)
    - 할당해야 할 메모리의 크기를 프로그램이 실행되는 동안 결정해야 하는 경우(런 타임 때) 유용하게 사용되는 공간
- Stack 영역
   - 함수 호출 시 생성되는 지역 변수와 매개 변수가 저장되는 영역
   - 함수 호출이 완료되면 사라짐