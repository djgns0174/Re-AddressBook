# Re-AddressBook (객체지향 주소록)

### 목표

- 앞서 만든 주소록에 대해서 객체지향적으로 바꾸는 프로젝트
- 객체지향 개념을 적용하여 이것이 c++이다 강의 내용 복습하는 차원
- MVC 개념을 적용 → 유지보수 용이성
- 모듈간의 결합도를 낮추고 코드의 가독성을 올리는것.

### HOW

- 사용자단에서 UI를 통해 model을 접근
    
    → 제어기를 통해 모델을 제어 (노드 추가, 삭제, 검색 등등)
    
    → 제어를 통한 모델의 변경을 UI에 적용 (주소록에 연락처 추가 등등)
    
- 자료구조, 노드, 대상자료에 대한 객체 분리
- 자료구조
    
    → 이진트리 : Root, size
    
    → 이중연결리스트 : Head, Tail, Size
    
- 노드
    
    → 이진트리 : left, right
    
    → 이중 연결 리스트 : prev, next
    
- 대상자료
    
    → 이름 : 전화번호
