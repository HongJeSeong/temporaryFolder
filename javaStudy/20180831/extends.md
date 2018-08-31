# 상속 extends !
```java
    public class Car{

    }

    public class Bus extends Car{

    }
    
    
```    
```java 
    
    
    
    
public class Car{
      public void run(){
          System.out.println("달리다.");
        }
    }
    
    
    
```

```java
  public class Bus extends Car{
        public void sound(){
            System.out.println("BRBRRBR");
        }       
    }
```
```java
public class BusExam{
        public static void main(String args[]){
            Bus bus = new Bus();
            bus.run();  
            //Bus class 는 아무런 코드를 가지지 않는다. 그럼에도 run 이라는 메소드를 사용하는데 문제가 발생되지 않는다. 
        }   
    }
    ```
