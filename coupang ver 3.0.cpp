#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string fullNumberArray[3000];   //풀송장번호를 저장할 배열 생성
string fullNumberArrayCopy[3000];//풀송장 번호를 역순으로 저장할때 사용할 배열 생성
string fourthNumberArray[3000];   //4자리 송장번호를 저장할 배열 생성
string unidentifyArray[3000];      //미확인 송장번호를 저장할 배열 생성

int helpNumberFull = 0;			//헬퍼에서 사용할 미확인 풀송장 번호를 카운팅할 변수 생성
int helpNumberFourth = 0;		//헬퍼에서 사용할 미확인 4자리 송장번호를 카운팅할 변수 생성



int helper(string num);		//오타난 송장번호 찾기 함수 선언


string starter = "r";   //r누르면 프로그램 리스타트. x는 종료

int main()
{


	while ((starter == "r") || (starter == "R") || (starter == "ㄱ")) {
		system("cls");

		helpNumberFull = 0;	//helper함수를 사용하기전에 초기화

		string checkup;   //풀송장번호와 4자리 송장번호를 비교할때 사용할 변수 생성
		string place;   //지역명을 저장할 변수 생성
		string str;      //문서에서 스트링 입력 받을때 사용할려고 생성. 필요할때 사용하면댐 아무떄나

		string sch = "서초";   //결과 출력때 이용할 지역명 변수 생성
		string asn = "안산";   //결과 출력때 이용할 지역명 변수 생성
		string hsn = "화성";   //결과 출력때 이용할 지역명 변수 생성
		string icn = "인천";   //결과 출력때 이용할 지역명 변수 생성
		string yin = "용인";   //결과 출력때 이용할 지역명 변수 생성
		string ynj = "양주";	//결과 출력때 이용할 지역명 변수 생성
		string sgp1 = "1송파";
		string sgp2 = "2송파";
		string isn1 = "1일산";
		string isn2 = "2일산";
		string dg = "대구";
		string success = "success ";
		string trash = "[";

		int num = 0;      //4자리 송장번호를 배열에 저장할때 사용할 변수 생성
		int fullNumberCount = 0;   //풀송장번호 개수를 저장하기 위해 변수 생성
		int fourthNumberCount = 0;   //4자리 송장번호 개수를 저장하기 위해 변수 생성

		int trashCheckNumber = 0;	//카톡드래그할때 버릴꺼 체크해줄 변수 생성

		int schCount = 0;      //서초를 카운트할 변수 생성
		int asnCount = 0;      //안산을 카운트할 변수 생성
		int hsnCount = 0;      //화성을 카운트할 변수 생성
		int icnCount = 0;      //인천을 카운트할 변수 생성
		int yinCount = 0;      //용인을 카운트할 변수 생성
		int ynjCount = 0;		//양주를 카운트할 변수 생성
		int sgp1Count = 0;		//송파를 카운트할 변수 생성
		int sgp2Count = 0;		//송파를 카운트할 변수 생성
		int isn2Count = 0;		//군포를 카운트팔 변수 생성
		int isn1Count = 0;		//군포를 카운트팔 변수 생성
		int dgCount = 0;
		int checkNumber = 0;   //풀송장번호, 미확인 풀송장번호 개수 체크할 변수 생성
		

		bool dawnCheck = false;		//새벽배송 송장번호를 체크해줄 변수 생성

		fstream ys;   //송장번호 텍스트파일을 불러오기 위해 객체 생성
		fstream cw; //4자리 송장번호 텍스트파일을 불러오기 위해 객체 생성



		ys.open("C:\\coupang\\dawn.txt");   //송장번호를 저장한 메모장을 읽어옴 

		cw.open("C:\\coupang\\kakao.txt");

		//for (int i = 0; !ys.eof(); i++) {   //풀송장번호를 배열에 저장(오직 풀송장번호만 저장할때 사용하던 코드)
		//	ys >> fullNumberArray[i];
		//	fullNumberCount++;
		//}



		while (true) {

			if (str == "[새벽배송]") {
				dawnCheck = true;
			}
			if ((dawnCheck == true) && (str.length() == 14)) {
				fullNumberArray[checkNumber] = str;
				checkNumber++;
				fullNumberCount++;
				dawnCheck = false;
			}
			if (ys.eof()) {
				break;
			}
			ys >> str;
		}

		for (int i = checkNumber-1; i >= 0; i--) {
			fullNumberArrayCopy[num] = fullNumberArray[i];
			num++;
		}

		num = 0;		//num 초기화
		str = "";	//str 초기화
		checkNumber = 0;	//미검증 풀송장 번호를 체크할 때 사용하기 위해 초기화

		while (true) {   //4자리 송장번호를 배열에 저장
						//지역명을 변수 place에 저장 

			cw >> str;

			if (cw.eof()) {

				break;
			}
			
			if (trashCheckNumber == 2) {	//카톡 드래그해서 버릴꺼버리기
				trashCheckNumber = 0;
				continue;
			}

			if (str[0] == trash[0]) {		//카톡 드래그해서 버릴꺼 버리기
				trashCheckNumber++;
				continue;
			}


			if (str == "서초" || str == "ㅅㅊ") {
				place = "서초";
			}
			else if (str == "안산" || str == "ㅇㅅ") {
				place = "안산";
			}
			else if (str == "화성" || str == "ㅎㅅ") {
				place = "화성";
			}
			else if (str == "인천" || str == "ㅇㅊ") {
				place = "인천";
			}
			else if (str == "용인" || str == "ㅇㅇ") {
				place = "용인";
			}
			else if (str == "양주" || str == "ㅇㅈ") {
				place = "양주";
			}
			else if (str == "1송파" || str == "1ㅅㅍ") {
				place = "1송파";
			}
			else if (str == "2송파" || str == "2ㅅㅍ") {
				place = "2송파";
			}
			else if (str == "군포" || str == "ㄱㅍ") {
				place = "군포";
			}
			else if (str == "1일산" || str == "1ㅇㅅ") {
				place = "1일산";
			}
			else if (str == "2일산" || str == "2ㅇㅅ") {
				place = "2일산";
			}
			else if (str == "대구" || str == "ㄷㄱ") {
				place = "대구";
			}

			else if (str == "") {		//공백 예외처리	

			}
			


			else {

				

				fourthNumberArray[num] = str + place;
				num++;
				fourthNumberCount++;


			}

			

		}

		for (int i = 0; i < fullNumberCount; i++) {         //송장번호 4자리 비교

			string number = fullNumberArrayCopy[i];
			for (int j = 0; j < fourthNumberCount; j++) {
				string number2 = fourthNumberArray[j];

				if (number[10] == number2[0] && number[11] == number2[1] && number[12] == number2[2] && number[13] == number2[3]) {

					fullNumberArrayCopy[i] = success + number2 + "\t" + fullNumberArrayCopy[i];   //지역확인한것
					fourthNumberArray[j] = success + fourthNumberArray[j];
					if ((number2[4] == sch[0]) && (number2[5] == sch[1])) {         //지역별 개수 카운팅
						schCount++;
					}
					else if ((number2[4] == asn[0]) && (number2[5] == asn[1])) {
						asnCount++;
					}
					else if ((number2[4] == hsn[0]) && (number2[5] == hsn[1])) {
						hsnCount++;
					}
					else if ((number2[4] == icn[0]) && (number2[5] == icn[1])) {
						icnCount++;
					}
					else if ((number2[4] == yin[0]) && (number2[5] == yin[1])) {
						yinCount++;
					}
					else if ((number2[4] == ynj[0]) && (number2[5] == ynj[1])) {
						ynjCount++;
					}
					else if ((number2[4] == dg[0]) && (number2[5] == dg[1])) {
						dgCount++;
					}
					else if ((number2[4] == sgp1[0]) && (number2[5] == sgp1[1]) && (number2[6] == sgp1[2])) {
						sgp1Count++;
					}
					else if ((number2[4] == sgp2[0]) && (number2[5] == sgp2[1]) && (number2[6] == sgp2[2])) {
						sgp2Count++;
					}
					else if ((number2[4] == isn1[0]) && (number2[5] == isn1[1]) && (number2[6] == isn1[2])) {
						isn1Count++;
					}
					else if ((number2[4] == isn2[0]) && (number2[5] == isn2[1]) && (number2[6] == isn2[2])) {
						isn2Count++;
					}
					break;
				}


			}

		}


		num = 0;   //num 초기화 후 카운트에 사용
		checkNumber = 0;
		for (int i = 0; i < fullNumberCount; i++) {         //결과물 출력
			str = fullNumberArrayCopy[i];
			if (str[0] != success[0]) {
				unidentifyArray[num] = str;
				num++;
				helpNumberFull++;
			}
			cout << fullNumberArrayCopy[i] << endl;
		}
		for (int i = 0; i < fourthNumberCount; i++) {
			str = fourthNumberArray[i];
			if (str[0] != success[0]) {
				unidentifyArray[num] = str;
				num++;
				helpNumberFourth++;
			}
			cout << fourthNumberArray[i] << endl;
		}

		/*for (int i = 0; unidentifyArray[i].length()==14; i++) {
			checkNumber++;
		}*/

		cout << "--------------------미확인---------------------" << endl;
		for (int i = 0; i < num; i++) {
			if (unidentifyArray[i] != "") {
				cout << unidentifyArray[i] << endl;
				if (unidentifyArray[i].length() == 14) {
					checkNumber++;
				}
			}
		}

		cout << "---------------------정리---------------------" << endl;
		cout << "서초  : " << schCount << "개" << endl;
		cout << "안산  : " << asnCount << "개" << endl;
		cout << "화성  : " << hsnCount << "개" << endl;
		cout << "인천  : " << icnCount << "개" << endl;
		cout << "용인  : " << yinCount << "개" << endl;
		cout << "양주  : " << ynjCount << "개" << endl;
		cout << "송파1 : " << sgp1Count << "개" << endl;
		cout << "송파2 : " << sgp2Count << "개" << endl;
		cout << "일산1 : " << isn1Count << "개" << endl;
		cout << "일산2 : " << isn2Count << "개" << endl;
		cout << "대구  : " << dgCount << "개" << endl;
		cout << "총합  : " << schCount + asnCount + hsnCount + icnCount + yinCount + ynjCount + sgp1Count + sgp2Count + isn1Count+ isn2Count << "개" << endl;
		cout << "미확인 풀송장번호 : " << checkNumber << "개" << endl;

		ys.close();
		cw.close();
		cin >> starter;

		if ((starter == "helper") || (starter == "HELPER")) {
			system("cls");
			cout << "찾고싶은 4자리 송장번호를 입력해주세요" << endl;
			cin >> starter;

			helper(starter);

			cin >> starter;


		}

	}
	system("pause");   //끝나고 콘솔창 유지
	return 0;

}

int helper(string num) {		//4자리 송장번호를 오타내고 보냈을때 비슷한 풀송장번호를 찾아줄 함수

	cout << endl << "3자리 일치 또는 4자리 일치 중에 선택해주세요" << endl;
	int fnum = 0;		//찾고싶은 송장번호를 입력받을 변수 생성
	cin >> fnum;
	cout << endl;

	string str;				//풀송장 번호를 저장할 변수 생성
	int helpCount = 0;		//4자리 송장번호와 풀송장번호끝4자리가 일치하는 횟수를 카운트해줄 변수 생성
	int findNumber = 0;
	int str1 = num[0];		//4자리 송장번호를 정렬하기 위한 변수 생성
	int str2 = num[1];
	int str3 = num[2];
	int str4 = num[3];
	int strf1 = 0;			//4풀송장번호를 정렬하기 위한 변수 생성
	int strf2 = 0;
	int strf3 = 0;
	int strf4 = 0;
	int swapArrayFourth[4] = { str1,str2,str3,str4 };


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (swapArrayFourth[i] > swapArrayFourth[j]) {
				swap(swapArrayFourth[i], swapArrayFourth[j]);
			}
		}
	}
	for (int i = 0; i < helpNumberFull; i++) {
		str = unidentifyArray[i];
		strf1 = str[10];
		strf2 = str[11];
		strf3 = str[12];
		strf4 = str[13];
		int swapArrayFull[] = { strf1,strf2,strf3,strf4 };


		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 4; j++) {
				if (swapArrayFull[k] > swapArrayFull[j]) {
					swap(swapArrayFull[k], swapArrayFull[j]);
				}
			}
		}

		/*if ((swapArrayFourth[0] == swapArrayFull[0]) && (swapArrayFourth[1] == swapArrayFull[1]) && (swapArrayFourth[2] == swapArrayFull[2]) && (swapArrayFourth[3] == swapArrayFull[3])) {
			cout << unidentifyArray[i] << endl;
		}*/
		for (int m = 0; m < 4; m++) {
			if (swapArrayFourth[m] == swapArrayFull[m]) {
				helpCount++;
			}
			if ((fnum == 3) && (helpCount == 3)) {
				cout << unidentifyArray[i] << endl;
				findNumber++;
				break;
			}
			if (helpCount == 4) {
				cout << unidentifyArray[i] << endl;
				findNumber++;
			}
		}
		helpCount = 0;

	}

	cout << endl << "확인해야할 풀송장번호는 " << findNumber << "개 입니다" << endl;
	cout << endl << "이전 화면을 보려면 R을 누르세요" << endl;

	return 0;


}

//template<class Any>
//inline void Swap(Any &a, Any &b) {
//	Any temp = a;
//	a = b;
//	b = temp;
//}
