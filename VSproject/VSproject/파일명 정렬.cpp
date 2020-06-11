#include <string>
#include <vector>
#include<algorithm>
using namespace std;

typedef struct {
	string name; // 파일명
	string head;  // HAED
	int number; // NUMBER
}fileData;

// 정렬 기준 함수 (HEAD, NUMBER 순서로 정렬)
bool comp(fileData a, fileData b) { 
	if (a.head == b.head) { 
		return a.number < b.number;
	}
	else
		return a.head < b.head;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<fileData> fileDatas;

	for (int i = 0; i < files.size(); i++) {
		string head="", number = "";
		int idx;

		for (int j = 0; j < files[i].size(); j++) {

			if (isdigit(files[i][j])) { // 숫자라면, HEAD가 끝났다는 뜻.
				idx = j; // 인덱스를 저장한다.
				break;
			}

			// HEAD 추출 : 대소문자 구분을 하지 않으므로, 모두 소문자로 변환하여 추출.
			head += tolower(files[i][j]); 
		}

		for (int j = idx; j < files[i].size(); j++) {

			// 숫자가 아니거나 5자리 이상이면, 중단.
			if (!isdigit(files[i][j]) || number.size() >= 5) {
				break;
			}

			// NUMBER 추출
			number += files[i][j]; 
		}

		// 파일명, HEAD, NUMBER을 구조체로 묶고, 구조체 배열에 넣는다.
		fileDatas.push_back({ files[i], head, stoi(number) });
	}
	
	// HEAD, NUMBER 순서로 stable sort를 수행한다.
	stable_sort(fileDatas.begin(), fileDatas.end(), comp);

	// 구조체에서 파일명만 추출하여 결과 벡터에 넣어준다.
	for (int i = 0; i < fileDatas.size(); i++)
		answer.push_back(fileDatas[i].name);

	return answer; // 결과 반환.
}
