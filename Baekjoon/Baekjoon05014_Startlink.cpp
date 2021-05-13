// Baekjoon5014.cpp
#include <iostream>

#include <queue>

using namespace std;

int main(void) {
	int maxFloor, startFloor, target, up, down;
	cin >> maxFloor >> startFloor >> target >> up >> down;

	bool visited[1'000'001] = { false, };
	visited[startFloor] = true;

	int ans = -1;
	queue<pair<int, int>> q;
	q.push( { startFloor, 0 } );
	while ( !q.empty() ) {
		pair<int, int> curr = q.front(); q.pop();
		if ( curr.first == target ) {
			ans = curr.second;
			break;
		}

		int upFloor = curr.first + up, downFloor = curr.first - down;
		if ( upFloor <= maxFloor && !visited[upFloor] ) {
			visited[upFloor] = true;
			q.push( { upFloor, curr.second + 1 } );
		}

		if ( 0 < downFloor && !visited[downFloor] ) {
			visited[downFloor] = true;
			q.push( { downFloor, curr.second + 1 } );
		}
	}

	if ( ans == -1 )
		cout << "use the stairs";
	else
		cout << ans;
	cout << '\n';

	return 0;
}