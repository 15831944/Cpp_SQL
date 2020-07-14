#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
//#include <functional>
//#include <cmath>
#include <queue>

#include "Header11.h"
//#include "add.h"
/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////헤더파일개념///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//#incdlue <> : c++ 런타임 라이브러리의 헤더 파일로써 운영체제의 특별한 위치에 존재한다.
//#include "" : 일반적으로 자산이 작성한 헤더파일을 include 한다.
int addd(int x, int y)
{
	return x+y;
}
/*define 관련 s메모리 누수 방지 메모리 릭이 발생 시 위치를 알려줌*/
//#define new DEBUG_NEW

using namespace std; 
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////(순수)가상함수//////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*부모클래스의 코드 설계*/
class Car
{

public:
	virtual void Drive()
	{
		//앞으로간다.
		cout<<"Drive()"<<endl;
		return;
	}
	virtual void Stop()
	{
		//멈춘다.
		cout<<"Stop()" <<endl;
		return;
	}
	virtual void Back()
	{
		cout<<"Back()" <<endl;
	}

	virtual void OpenDoor() = 0; //순수가상함수1
	virtual void CloseDoor() = 0; //순수가상함수2
};
/*슈퍼카 클래스의 코드 설계*/
class SuperCar : public Car // Car에서 상속받기
{
public:
	virtual void OpenDoor()  
	{
		//위로 열린다.
		cout<< "super-open()" <<endl;
		return;
	}
	virtual void CloseDoor()  
	{
		//아래로 닫힌다.
		cout<<"super - close()" <<endl;
		return;
	}

};
/*일반카 클래스의 코드 설계*/
class NormalCar : public Car // Car에서 상속받기
{
public:
	virtual void OpenDoor()  
	{
		//옆으로열린다.
		cout<< "normal-open()" <<endl;
		return;
	}
	virtual void CloseDoor()  
	{
		//옆으로 닫힌다.
		cout<<"normal - close()" <<endl;
		return;
	}

};

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////벡터 && 구조체 개념/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/*구조체를 벡터에 저장하는 예제*/
struct Score
{
	string name;
	int korean;
	int english;
	int math;
}; 

/* sort 구조체 정렬 */
struct PP
{
	int x;
	int y;
};

/* 구조체와 클래스의 차이*/
struct point2D
{
	int x;
	int y;

};

class Point2D2
{
	
public :
	int x;
	int y;
	void Init()
	{
		x=12;
		y=12;
	}

};

/*포인터와 레퍼런스의 차이*/
//1.NULL 허용 여부 : 포인터는 NULL을 허용하지만, 레퍼런스는 NULL이 될 수 없다.
struct personer
{
	int birthday;

};




/*구조체 생성자로 초기화 202004029 */
struct _MY_STRUCT
{
	char c;
	int i;
	char sz[100];
};

/*일반적인 구조체 선언 후 초기화 */
_MY_STRUCT ggg;




/*생성자에서 초기화*/
typedef struct _MY_STR
{
	char c;
	int i ;
	char sz[100];
	_MY_STR()
	{
		memset(this,0x00,sizeof(struct _MY_STR));
	}
} MY_STRC;
MY_STRC sst; //선언과 동시에 초기화



/*typedef 함수 포인터 구현 */
void (*ptrfunc)(int) ; //함수 포인터 : return값의 자료형(*포인터 함수의 이름)(인자값)
void testprint(int n)
{
	printf("Number : %d \n" , n);

} 
typedef void (*ptrfunc2)(int);
void testprint2(int nn)
{
	printf("Number : %d \n" , nn);
}

/* sort 구조체 정렬  */

bool cmp (const Score &p1 , const Score &p2)
{
	if(p1.english == p2.english)
	{
		if(p1.korean < p2.korean)
		return true; //오름차순 
	}else
	{
		true;
	}
	
}
bool Vcomp (const pair<int,int> &p1, const pair<int,int> &p2)
{
	if(p1.first < p2.first) //first 기준으로 정렬
		return true;
	else if ( p1.first==p2.first)
	{
		if(p1.second < p2.second) //second를 기준으로 정렬 
		{
			return true;
		}
	}

	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////템플릿//////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
 
template <typename T>
T Testsum(T a, T b)
{
	return a+b;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////몇개뽑기(중복허용OX)////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
bool vii[10];

vector <int > vvvvv_;
int ex_Num[5] ={1,2,3,4,5};
void Permutition(int ctttt, int num )
{
	if(ctttt==3)
	{
		vector <int > ans;		
		for(int i = 0 ; i < vvvvv_.size() ; i++)
		{
			cout <<" " <<vvvvv_[i]   ; 
		}
		cout<< endl;
		return ;
	}


	for(int w= 0 ; w<5 ;w ++)
	{
		//if(!vii[w])
		//{	
		vii[w]=true;
		vvvvv_.push_back(ex_Num[w]); //0	
		Permutition(ctttt+1,w);
		vvvvv_.pop_back(); 
		vii[w] =false;
		//} 
	}

}
void Combination(int ctttt, int num )
{
	if(ctttt==3)
	{
		vector <int > ans;		
		for(int i = 0 ; i < vvvvv_.size() ; i++)
		{
			cout <<" " <<vvvvv_[i]   ; 
		}
		cout<< endl;
		return ;
	}


	for(int w= num ; w<5 ;w ++)
	{
		//if(!vii[w])
		//{	
		vii[w]=true;
		vvvvv_.push_back(ex_Num[w]); //0	
		Combination(ctttt+1,w);
		vvvvv_.pop_back(); 
		vii[w] =false;
		//} 
	}

}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////this (자기자신)/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

class A
{
	int num;
public:
	A (int num)
	{
		this->num=num;

	}
	int get_Num()
	{
		return num;

	}
	void print_This()
	{
		cout<<"Class of A of Adress : " << this << endl;
	}
	A * return_A()
	{
		return this;
	}
};

int Header112::width()
{
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////MAIN///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
int main ()
{  
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////set iterator///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	set <int > sp;
	//iterator
	for (set<int>::iterator it = sp.begin(); it != sp.end(); it++)
	{
		cout << *it << endl;
	}

	for (auto i : sp)
		cout << i << " ";



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////열거형 변수 enum/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	enum Color
	{
		COLOR_BLACK, //assigned 0
		COLOR_RED,   //assigned 1
		COLOR_BLUE,  //assigned 2
		COLOR_GREEN, //assigned 3
		COLOR_WHITE, //assigned 4 
	};// enum 자체는 세미콜론으로 끝나야함.

	
	//열거형 Color의 변수들 정의
	Color paint = COLOR_WHITE;
	Color house(COLOR_BLUE);
	Color apple
	{
		COLOR_RED
	}; 

	enum Color2
	{
		RED,
		BLUE,
		GREEN
	};

	enum Feeling
	{
		HAPPY,
		TIRED,
		BLUE2  // error, BLUE is already used in enum Color2 in the global namespace ! 
	};


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////substr 예제/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
	/*
		https://www.naver.com
		1)http:// 짜르고  0~4 
		2)www.따르고 5~7 
		3)naver. 짜르고 8 ~
		4)com 짜르기 끝까지 
	*/  
	string strURL = "https://www.naver.com";
	string strRelut[4];
	int end=0;
	int arrNumx = 0;
	int scnt = 0;
	//아이디어  : w만나면 앞에까지 짤르기
	/*for (int i = 0; i < strURL.size(); i++)
	{
		
		if (strURL[i] == '/')
		{
			scnt++;
			if (scnt > 1)
			{
				strRelut[arrNumx++] = strURL.substr(0, i);
				end = i + 2;
				break; 
			}else
			{
				continue;
			
			}
			
		}
		if (strURL[i] == '.')
		{
			strRelut[arrNumx++] =strURL.substr(end , i);
			end = i + 1;
			break;
		}
		else
		{
			strRelut[arrNumx++] = strURL.substr(end, i);
		}
		

	}*/
	//.만나면 방금맨끝에서 그앞까지 짜르기
	//너머지 처리하기
	//1 0~6
		
	//2 7~ .까지
	
	//3 그담부터 .까지
	
	//4 그담부터 마지막까지 


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////this (자기자신)/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
cout << "/////////////////////////////////////////////////////////////////////////// " << endl;
cout << "///////////////////////////////////NextPermutation///////////////////////// " << endl;
cout << "/////////////////////////////////////////////////////////////////////////// " << endl;

vector <int> Next;
for (int i = 0; i < 3; i++) Next.push_back(i);
do 
{
	for (int i = 0; i < 3; i++)
	{
		cout << Next[i];

	}
	cout << endl;
} while (next_permutation(Next.begin(), Next.end()));


cout << "/////////////////////////////////////////////////////////////////////////// " << endl;
cout << "///////////////////////////////////NextPermutation///////////////////////// " << endl;
cout << "//////////////////////////////////Combination////////////////////////////// " << endl;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////넥퍼뮤 순열//////////////////////////////////////////
/////////////////////////////////////넥퍼뮤 이용 조합 구하기///////////////////////////////////
/*
	길이가 7인 배열에서 길이가 6인 수열을 구한은 프로그램
	순열은 뽑는 방법이므로 순서가 중요하지 않다. 7C6 이므로 7가지 ==> 조합 
*/
int arrCombination[7] = { 1,2,3,4,5,6,7 };
bool tmpCombination[7] = { 0,0,0,0,0,0,1 }; // pick->'0', pass->'1' 

 
/*순열 ABC 순서대로 */

vector <string> CC;
CC.push_back("A");
CC.push_back("B");
CC.push_back("C");
do
{
	for (int i = 0; i < CC.size(); i++)
	{
		cout << CC[i] << " ";
	}
	cout << endl;

} while (next_permutation(CC.begin(), CC.end()));


//7C1 구현
int temp0[7] = { 0,0,0,0,1,1,1 };
cout << "%%%%%%%%%%%%7C1 Combination%%%%%%%%%%" << endl;
do
{
	for (int i = 0; i < 7; i++)
	{
		if (temp0[i] == 0)
		{
			cout << arrCombination[i] << " ";
		}
	}
	cout << endl;
} while (next_permutation(temp0, temp0 + 7));
 
 


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////this (자기자신)/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


cout <<"/////////////////////////////////////////////////////////////////////////// "  <<endl;
cout <<"///////////////////////////////////This//////////////////////////////////// "  <<endl;
cout <<"/////////////////////////////////////////////////////////////////////////// "  <<endl;
	A aab(100);
	A *abf =  new A(100);
	cout<<"Adress of aab : " << &aab << endl;
	cout<<"*temp test1 : " << abf <<endl;
	cout<<"*temp test2 : " << abf->get_Num() <<endl;
	aab.print_This();
	cout<<"a.return_aab() : " << aab.return_A() <<endl;

	A aa(10);
	cout<<"aa.get_Num :  "<<aa.get_Num() <<endl;


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////몇개뽑기(중복허용OX)////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//중복허용

	cout <<"/////////////////////////////////////////////////////////////////////////// "  <<endl;
	cout <<"///////////////////////////////////Combination///////////////////////////// "  <<endl;
	cout <<"/////////////////////////////////////////////////////////////////////////// "  <<endl;
Combination(0,0);
//중복X

	cout <<"/////////////////////////////////////////////////////////////////////////// "  <<endl;
	cout <<"///////////////////////////////////Permutition///////////////////////////// "  <<endl;
	cout <<"/////////////////////////////////////////////////////////////////////////// "  <<endl;
Permutition(0,0);

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////템플릿//////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	cout <<"/////////////////////////////////////////////////////////////////////// "  <<endl;
	cout <<"///////////////////////////////////Tempate///////////////////////////// "  <<endl;
	cout <<"/////////////////////////////////////////////////////////////////////// "  <<endl;
	/*
		함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료 형으로 사용할 수 있도록 하게 만들어 놓은 툴
		함수 텔플릿(Function Template)와 클래스 템플릿(Class Template)로 나뉨 
	*/

	int a=1,b=2;
	double d1=2.2,d2=3.3;
	string sss1= "show me" , sss2= "the money 6";
	cout<<"int sum : " << Testsum<int>(a,b) <<endl;
	cout <<"double sum : " << Testsum<double>(a,b) <<endl;
	cout <<"string sum : " <<Testsum<string>(sss1,sss2) <<endl;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////(순수)가상함수//////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	cout <<"/////////////////////////////////////////////////////////////////////// "  <<endl;
	cout <<"/////////////////////////////(pure)virtual func//////////////////////// "  <<endl;
	cout <<"/////////////////////////////////////////////////////////////////////// "  <<endl;

	cout<< "1> Drive & OpenDoor OF SUPERCAR" <<endl;
	SuperCar* pSuper = new SuperCar; // 동적할당
	pSuper->Drive();
	pSuper->OpenDoor();

	cout<< "2> Drive && OpenDoor OF NORMALCAR" <<endl;
	NormalCar* pNormal = new NormalCar;
	pNormal->Drive();
	pNormal->OpenDoor(); 

/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////8(Octal), 10(Decimal), 16(Hexadecimal) Trans//////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	cout <<"/////////////////////////////////////////////////////////////////////// "  <<endl;
	cout <<"////////////8(Octal), 10(Decimal), 16(Hexadecimal) Trans/////////////// "  <<endl;
	cout <<"/////////////////////////////////////////////////////////////////////// "  <<endl;
	/*
		8진수는 10진수에 0을 붙여준다.
		10진수는 그대로
		16진수는 10진수에 0x를 붙여준다.

	*/
	int decimal = 41;
	int octal = 041;
	int hexadecimal = 0x41;
	//1. 10진수 41을 8진수, 16진수로 표현하기
	cout << "41(10) : " << decimal <<endl; //41
	cout << "41(8) : " << octal << endl; //33
	cout << "41(16) : " <<hexadecimal <<endl; //65 
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////16진수 입력 방법/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	string ans = "FA92"; //16진수 스트링으로 표현 
	int res = pow(12.2,12);


	
	
	for(int i= 0 ; i< ans.size() ; i++)
	{
		int a;
		int b= ans.size()-i-1;
		a=pow(16.0, b);
		if(ans[i]-'0' <10)
		{
			a*=(ans[i]-'0');
		}else
		{
			a*=(ans[i]-'7');
		}
		res +=a;
	
	}

/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////자료구조///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		Vector 예제
	*/
	cout << "/////////////////////////////////////// " << endl;
	cout << "///////////////VECTOR EX/////////////// " << endl;
	cout << "/////////////////////////////////////// " << endl;
	//Vector Pair 관련
	vector<pair<int,int>> pair2;
	vector<pair<int,pair<int,int>>> pair3;
	queue<pair<int, string>> qpair;
	pair2.push_back({ 1,2 });
	qpair.push({ 1,"하이" });
	
	cout <<"about vector pair" <<pair2[0].first << endl;
	cout <<"about vector pair" <<pair2[0].second << endl;
	cout << "about queue pair" << qpair.front().first << endl;
	cout << "about queue pair" << qpair.front().second << endl;
	 /*
		구조체를 벡터에 저장하는 예제
		구조체 배열은 vv[0].english vv[1].korean 등으로 저장되는 형태
		2차원 벡터랑은 조금 차이가있다.
	*/ 
	vector<Score> vv;
	Score score1;
	score1.korean = 123;
	score1.english = 123;
	
	Score score2;
	score2.korean = 123;
	score2.english = 123;

	vv.push_back(score1);
	vv.push_back(score2); 

	//sort(vv.begin(),vv.end(),Vcomp);
	
	vector<Score> ss;
	Score temmm;
	//memset(ss,0,sizeof(ss));
	//memset(temmm,0,sizeof(temmm));
	temmm.english =30 ;
	temmm.korean = 20;
	ss.push_back(temmm);
	
	/*
		2차원 벡터는 Vec2D[0][1] Vec2D[0][2] 이런식으로 말그대로 2차원배열생성느낌
	*/
	//2차원벡터 생성방법
	vector<int> vec1;
	vector<int> vec2;
	vector<vector<int>> Vec2D;

	vec1.push_back(0); //vec1 = 0,1
	vec1.push_back(1);

	vec2.push_back(0); //vec2 = 0,1,2,3
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);

	Vec2D.push_back(vec1);
	Vec2D.push_back(vec2);
	cout<< endl;
	//출력
	/*
		Vec2D
		0-0,1
		1-0,1,2,3
	*/  
	cout <<"/////////////////////////////////////// "  <<endl;
	cout <<"////////////2D VECTOR EX/////////////// "  <<endl;
	cout <<"/////////////////////////////////////// "  <<endl;
	
	for(int i =0 ; i<Vec2D.size() ; i++ )
	{
		for(int j = 0 ; j <Vec2D[i].size() ; j++)
		{
			cout<<"2D Vector[" << i << "]" << "[" << j << "]"  << " : " <<Vec2D[i][j] <<  endl ;
		}
			cout<<endl;
	}
	/*
		자료구조 Map
		key, value를 가지는 자료구조
		key값은 중복허용 X 중복 등록 시 map에 안담긴다.
		정렬 여부 X 
		multimap은 key값을 중복으로 가질수 있다.
	*/
	cout <<"/////////////////////////////////////// "  <<endl;
	cout <<"/////////////////////Map/////////////// "  <<endl;
	cout <<"/////////////////////////////////////// "  <<endl;
	/*자료구조 Map*/
	map<string,int> m;
	m.insert(make_pair("aaqwe",231));
	m.insert(make_pair("b",2123));
	m.insert(make_pair("c",333));
	m.insert(make_pair("d",4));
	m.insert(make_pair("e",5));
	m.insert(make_pair("e",5));
	m.insert({ "e",5 });
	map<int,int> :: iterator iter; 
	map<int,int> mm;
	mm[11]=200;  //key value 삽입
	mm[12]=200;	
	mm[0] =30;
	/*
		중요부분 Map 출력
	*/ 

	for(iter=mm.begin(); iter!=mm.end();++iter)
	{

		cout <<"( " << iter->first <<", " <<iter->second << ")" << " "  ; 
	} 
	cout<< endl;
	map<string,int> :: iterator it; 
	for(it=m.begin();it!=m.end();++it)
	{
		cout <<"( " << it->first <<", " <<it->second << ")" << " "  ; 
		
	}
	cout<< endl;
	//count(key) 
 
	cout<<"Map a count :" <<m.count("a") << endl;
	cout <<"Map b count :" << m.count("b") <<endl;

  
 
	/*
		자료구조 Set
		1) 노드 기반 컨테이너
		2) 균형 이진트리로 구현
		3) key값은 중복X
		4) 원소가 자동으로 정렬됨(오름차순)**

	*/
	cout <<"/////////////////////////////////////// "  <<endl;
	cout <<"/////////////////////set/////////////// "  <<endl;
	cout <<"/////////////////////////////////////// "  <<endl;
	set<int> s1;
	set<pair<int,int>> ss2;

	//set입력
	s1.insert(9);
	s1.insert(8);
	s1.insert(7);
	s1.insert(6);
	s1.insert(5);
	s1.insert(4);
	s1.insert(4);
	s1.insert(4);

	//pair
	ss2.insert(make_pair(1,2)); 
	ss2.insert(make_pair(1,2)); 
	ss2.insert(make_pair(1,2)); 
	ss2.insert(make_pair(1,2)); 
	ss2.insert(make_pair(1,2)); 
 
	set<int> ::iterator ii;
	for(ii =s1.begin() ; s1.end()!=ii ; ii++)
	{
		cout<<"set value " << *ii<<endl; ;  //예상 4,5,6,7,8,9

	}
	set<int,int> :: iterator itrs; 
 
	//find 
	ii=s1.find(9);
	if(ii != s1.end())
	{	cout << " Have you 9 ? " <<endl;
		cout<<   *ii <<"is have"<<endl;

	}else
	{
		cout<<"have not" <<endl;

	}
 


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////구조체 //////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

	cout <<"/////////////////////////////////////////////// "  <<endl;
	cout <<"////////////////struct & class///////////////// "  <<endl;
	cout <<"/////////////////////////////////////////////// "  <<endl;
	/* sort 구조체 정렬 */
	//PP a[100];
	//sort(a,a+100,cmp);  
	PP tem;
	PP tem2;
	tem.x = 10;
	tem.y = 10;
	tem2.x=20;
	tem2.y=30;
	//sort(tem,tem2,cmp);
	
	int test(300);
	//cout<<"test : " << test << endl;
	cout<<endl;
 
	/* 
		구조체와 클래스의 차이 : 
		구체는 접근제어 지시자를 선언하지 않으면 public으로 클래스는 private로 선언
	*/
	Point2D2 p1;
	p1.Init();
	int temp = p1.x;
 
	cout << temp <<endl; 

	struct personer *peter = NULL; //에러발생
	if(peter)
	{
		peter->birthday =1220;
	}
	else 
	{
		cout<<"peter is null" <<endl;
	} 

	/*
		구조체할당관련
	*/
	struct P
	{

		int a;
		int b;
	};
	P* ptr =new P;

	delete ptr;
 
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////레퍼런스 & 포인터/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

	/*포인터와 레퍼런스의 차이*/
	//2.참조 대상 할당 및 접근 &연산을 통해 주소값을 할당 
	/* 
		결론 :  레퍼런스는 포인터를 잘못 사용해서 생기는 수많은 
				문제들을 최소화하기위해생김
				Use references when you can, and pointers when you have to
				사용할 수 있다면 참조자를 써라, 어쩔 수 없다면 포인터를 써라
				출처: https://gracefulprograming.tistory.com/11 [Peter의 우아한 프로그래밍]
				int aaa=10;
				int *p = &aaa;
				int &p =aaa;
	*/
	cout<<endl;
	cout <<"/////////////////////////////////////// "  <<endl;
	cout <<"////////////Function Pointer/////////// "  <<endl;
	cout <<"/////////////////////////////////////// "  <<endl;

	/*typedef 함수 포인터 구현 */
	testprint(100);
	ptrfunc =testprint; //함수 포인터가 사용하고자하는 함수 같은 동작을 하게됨
	ptrfunc(77);

	testprint2(100);
	ptrfunc2 elecs; // elecs = ptrfunc2 
	elecs = testprint2;
	elecs(77);

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////이중 포인터 /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		포인터 : 실제로는 변수여서 멤모리 주소를 구할 수 있음 
				 하지만, 메모리 주소는 일반 포인터에 저장X --> 이중 포인터에 저장
	*/
	int *numPtr1;  // 단일 포인터
	int **numPtr2;  //이중 포인터
	int num = 10;
	
	numPtr1 = &num; //num1의 메모리 주소 저장.
	numPtr2 = &numPtr1; //numptr1의 메모리 주소 저장

	cout<< numPtr2 <<endl;
	cout << **numPtr2 <<endl; //20 포인터를 두 번 역참조 

	int num1 = 10 , num2 = 20, num3=30;
	int *parr[3];

	parr[0] = &num1;
	parr[1] = &num2;
	parr[2] = &num3;
	cout <<"/////////////////////////////////////// "  <<endl;
	cout <<"////////////////** Pointer///////////// "  <<endl;
	cout <<"/////////////////////////////////////// "  <<endl;

	for(int i = 0 ; i < 3 ; i++ )
	{
		cout<<i << " " << *parr[i] <<endl;

	}
 
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////헤더 파일개념 /////////////////////////////////////// 
/////////////////////////////////////////////////////////////////////////////////////////////
	cout <<"/////////////////////////////////////// "  <<endl;
	cout <<"////////////Header Method////////////// "  <<endl;
	cout <<"/////////////////////////////////////// "  <<endl;
	cout<< addd(3,4) <<endl;

	return 0;
}
