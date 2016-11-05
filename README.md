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

### Javascript
- Script 언어이므로 interpreter에 의해 실행된다.
- Object 기반의 언어이며 Single Thread이다.

#### Method Chaining이란, 어떻게 구현할지


#### Node.js Single Thread 처리 방식, 장점, 어떤 경우에 안좋고 어떨때 좋은지



### C++

#### C++ Virtual Function
- 가상 메소드는 그 메소드를 호출하는 객체가 어떤 클래스인지에 따라 구현이 결정되는 메소드를 뜻한다.
- 자바의 경우, 정적 메소드를 제외한 모든 함수가 가상 메소드이며, C++의 경우 virtual 키워드를 선언해야 한다.
- 예부터 살펴보자.

```C++
class Parent {
    public:
        void say(){ std::cout << "parent's say" << endl; }
};

class Child : public Parent {
    public:
        void say(){ std::cout << "child's say" << endl; }
};

int main()
{
    Child* a = new Child();
    a->say();   // child's say 출력

    Parent *b = new Child();
    b->say();   // parent's say 출력

    return 0;
}
```

- 위에서 Parent 클래스의 포인터를 사용했지만, 실제 객체는 Child의 Instance 임에도 불구하고, Parent's say가 출력된다.

- 하지만 아래와 같이 virtual을 사용하는 경우

```C++
class Parent {
    public:
        virtual void say(){ std::cout << "parent's say" << endl; }
};

class Child : public Parent {
    public:
        void say(){ std::cout << "child's say" << endl; }
};

int main()
{
    Parent* a = new Child();
    a->say();   // child's say 출력

    return 0;
}
```

- child's say가 출력이 된다. virtual 키워드를 선언함으로써, Pointer의 타입이 아닌 Instance의 Type을 인지하여 호출한다.
- 바로 virtual이 이런 dynamic binding(late binding)이 가능하게 해주는 keyword이기 때문이다. 포인터의 타입이 아닌 실제 객체의 타입을 알아서 virtual function table을 찾아 동적으로 호출하는 것이다.
- 반면, virtual이 없는 함수들은 compile time binding이다. 이미 무엇을 호출할지 정해져 있다.
- Virtual class도 마찬가지다. pointer에 상관 없이 dynamic binding 이기 때문에 instance의 type에 맞는 method를 접근할 수 있게 된다.
- Ref: [C++Virtual Function](http://rapapa.net/?p=346)



#### 소멸자에 virtual을 쓰는 이유

- A클래스가 부모클래스, B클래스가 자식클래스 일때, 생성자의 호출 순서는 A::A(), B::B() 순서로 호출된다. 소멸자의 경우, 생성자의 반대 순서로 B::~B(), A::~A() 순서다.
- 다형성 이용을 위해 A클래스의 포인터로부터 B클래스를 호출할 때, 가상 함수로 정의되지 않은 B클래스의 오버라이딩된 함수를 호출하면 A클래스의 멤버 함수가 호출된다.
- 소멸자도 B클래스에서 오버라이딩된 함수라고 볼 수 있기 때문에 만약 A포인터로 객체를 삭제하면 A클래스의 소멸자가 호출된다. 따라서 소멸자를 가상 함수로 선언하지 않으면 이 경우 B클래스의 소멸자는 결코 호출되지 않는다.
- 가상 함수 키워드 virtual이 사용되었다면 이것은 B클래스에서 재정의될 수 있음을 명시하기 때문에 포인터의 종류에 상관없이 항상 B클래스의 메서드가 호출된다.
- 즉, 자식 클래스의 소멸자가 호출되고 나서 부모 클래스의 소멸자가 호출된다. 따라서 상속 관계가 있고 소멸자에서 리소스를 해제해야 하는 경우 반드시 소멸자를 가상 함수로 선언해야 한다.
- Ref: [C++/소멸자에 virtual을 쓰는 이유](http://hyacinth.byus.net/moniwiki/wiki.php/C%2B%2B/%EC%86%8C%EB%A9%B8%EC%9E%90%EC%97%90%20virtual%EC%9D%84%20%EC%93%B0%EB%8A%94%20%EC%9D%B4%EC%9C%A0)

#### C++ static
- 전역변수에 선언된 static
    - 선언된 파일 내에서만 참조를 허용하겠다는 의미
- 함수 내에 선언된 static의 의미
    - 한번만 초기화되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다.
- 초기값을 주지 않을 경우 항상 0 으로 초기화 되며 프로그램을 실행시킬 때 단 한번만 초기화된다. 
- static 멤버변수(클래스 변수)
    - static 멤버변수는 '클래스 변수'라고도 불린다. 일반적인 멤버변수와 달리 클래스당 하나씩만 생성되기 때문이다. 클래스 안에 선언된 static 변수의 경우 별개의 메모리에 할당되는 변수가 아닌 모든 객체가 공유하는 구조가 된다.
    - static 멤버변수는 생성자에서 초기화하면 안된다. static 멤버변수는 객체가 생성될때 동시에 생성되는 변수가 아니고, 이미 메모리공간에 할당이 이뤄진 변수이기 때문이다. 따라서 static 멤버변수의 초기화 문법은 다음과 같이 별도로 정의되어 있다.
    ```C++
        int student::objCnt; // static 멤버변수의 초기화 문법
    ```
- static 멤버함수
    - static 멤버함수 역시 그 특성이 static 멤버변수와 동일하다.
    - 선언된 클래스의 모든 객체가 공유한다.
    - public으로 선언이 되면, 클래스의 이름을 이용해서 호출이 가능하다.
    - 의 멤버로 존재하는 것이 아니다.

#### C++ 자료형(32bit)

| 구분   | 자료형        | 크기    |
|--------|---------------|---------|
| 문자형 | char          | 1 byte  |
|        | unsigned char | 1 byte  |
| 정수형 | int           | 4 byte  |
|        | unsigned int  | 4 byte  |
|        | short         | 2 byte  |
|        | long          | 4 byte  |
|        | unsigned long | 4 byte  |
| 실수형 | float         | 4 bytte |
|        | double        | 8 byte  |



### Java

#### Java static 
- static 변수(즉 정적변수)란  
    - Class 당 하나만 생성되는 변수, 객체(인스턴스)를 아무리 많이 만들더라도 변수는 하나만 존재 
    - 객체가 생성될 때마다 새롭게 생성되는 멤버 변수와는 달리 초기에 한번만 생성되고 공유하여 사용가능 
- static 변수 생성 시기
    - Class 이름이 언급되어 질때 생성 (new 뿐만 아니라 Class 명만 나와도 생성됨)
- static 변수 초기화 방법 
    - static 변수 는 초기 생성시 초기화 
    
    ```java
    public static int sTotal=0;
    ```

    - static 변수 는 초기 생성시 초기화. 최초 1회만 호출됨. 
    
    ```java
        public static int sTotal=0; 
        public int nTotal=0; 
        static { 
            sTotal += 10; 
            //nTotal += 10; //Static initializer 사용시 사용할 수 없다는 메시지 발생 
        } 
    ```
    
---

## Database
### 정규화란?
- 관계형 데이터베이스의 설계에서 중복을 최소화하게 데이터를 구조화하는 프로세스를 정규화라고 한다. 
- 데이터베이스 정규화의 목표는 이상이 있는 관계를 재구성하여 작고 잘 조직된 관계를 생성하는 것에 있다. 일반적으로 정규화란 크고, 제대로 조직되지 않은 테이블들과 관계들을 작고 잘 조직된 테이블과 관계들로 나누는 것을 포함한다. 정규화의 목적은 하나의 테이블에서의 데이터의 삽입, 삭제, 변경이 정의된 관계들로 인하여 데이터베이스의 나머지 부분들로 전파되게 하는 것이다.
- Ref: [데이터베이스_정규화](https://ko.wikipedia.org/wiki/%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4_%EC%A0%95%EA%B7%9C%ED%99%94)

### MongoDB
- MongoDB의 특징 
    - Flexibility: Schema-less 구조를 취함으로써 다양한 형태로 데이터를 저장 할 수 있다.
    - Performance: Read&Write 성능이 뛰어나다
    - Scalability: RDBMS의 한계로 잘 알려진 데이터 수용량을 확대 하고자 Scale Out 구조를 채택 함으로 인해 많은 데이터를 저장 할 수 있다.
    
- MongoDB의 장점
    - Schema-less(Document Based): 데이터 모델의 유연한 변화가 가능하다. 데이터 모델에 대한 변경,추가 필드 확장이  간단하다. 그러나 RDBMS의 경우 스키마 변경에 따른 추가 작업이 필요 하다.
    - Structure of a single object is clearer: 가독성 측면에서 볼 때, json 구조를 사용하기 때문에 RDBMS 테이블 구조에 비해 데이터를 직관적으로 파악 할 수 있다.
    - No sql or hibernate queries (complex joins): MongoDB의 장점 중 하나는 사용하기 쉽다는 점다. 비교적 간단한 형태로 기존의 RDBMS의 SQL언어를 대체 할 수 있다. (i,e, $gt, $lt, )
    - Tuning: consistency의 레벨이 컨트롤 가능 하기 때문에 성능에 중점을 두거나 또는 정합성에 중점을 둘지 선택 가능하다.
    - Ease of scale-out: Auto sharding을 지원 함으로서 장비 확장이 RDBMS 대비 간단하다.

- MongoDB의 단점
    - 만약 데이터 업데이트 중 장애가 발생한다면 데이터 손실이 발생할 수 있다. 따라서 중요데이터는 가급적 분리 보관을 추천한다.
    - 데이터의 복제 기능을 지원 하기는 하나 완전한 원복을 원한다면 데이터 센터를 분리해서 설치 해야 한다.
    - 인덱스 구조는 메모리에 저장 되기 때문에 많은 인덱스를 사용한다면 충분한 메모리를 사용하기 바란다.
    - 데이터는 필드네임과 함께 사용해야 함으로 데이터 공간 소모가 RDBMS 대비 많을 가능성이 있다.
    - 복잡한 join 사용시 성능 제약이 있다.Document Based 구조 임으로 가급적 join을 회피하는 구조로 사용해야 한다.  

- Summary
    - 데이터 전반적인 가이드의 결론은 많은 양의 데이터와 쓰기 읽기등 퍼포먼스에 치중한다면 MongoDB를, transaction과 같은 정합성 위주의 시스템을 사용한다면 RDBMS를 사용하기를 추천한다.

- Ref: (NoSQL – MongoDB를 RDBMS의 대안으로 고민 중이라면 참고할 만한 글)[hochul.net/blog/nosql_mongodb_rdbms_alternative]

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

### TCP/IP 
- Server: socket() -> bind() -> listen() -> accept() -> read()/write() -> close()
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;↑
- Client: socket() ----------------------> connect() -> read()/write() -> close()


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
