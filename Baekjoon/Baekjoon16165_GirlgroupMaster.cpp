// Baekjoon16165_GirlgroupMaster.cpp
// https://www.acmicpc.net/problem/16165
#include <iostream>

#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> memberData; // 각 Member의 Team 정보
	map<string, vector<string>> teamData; // 각 Team의 Member List
	for ( int i = 0; i < n; i++ ) {
		string team; // Team name
		cin >> team;

		int memberNumber;
		cin >> memberNumber;

		// Team에 대한 정보가 하나도 없기 때문에, 그 Team에 대한 list 생성해줌
		teamData[team] = vector<string> ();
		for ( int j = 0; j < memberNumber; j++ ) {
			string member; // Member name
			cin >> member;

			teamData[team].push_back( member ); // Team에 member 추가

			memberData[member] = team; // 그 member의 Team 정보 추가
		}

		// Member List를 출력할 때 사전순으로 출력해야함
		sort( teamData[team].begin(), teamData[team].end() );
	}

	for ( int i = 0; i < m; i++ ) {
		string name;
		cin >> name;

		int quiz;
		cin >> quiz;

		// 0일 땐 Member List 출력
		if ( quiz == 0 )
			for ( string& name : teamData[name] )
				cout << name << '\n';
		// 1일 땐 그 Member의 Team 정보 출력
		else
			cout << memberData[name] << '\n';
	}

	return 0;
}