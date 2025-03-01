#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fixTime(int time) {
    int hours = time / 100;
    int minutes = time % 100;

    if (minutes >= 60) { 
        hours += minutes / 60;
        minutes = minutes % 60;
    }

    if (hours >= 24) { 
        return 0; 
    }

    return (hours * 100) + minutes; 
}

void findCommonTime(vector<pair<int, int>> times) {
    int commonStart = 0, commonEnd = 2359;

    for (auto t : times) {
        commonStart = max(commonStart, fixTime(t.first));
        commonEnd = min(commonEnd, fixTime(t.second));   
    }

    if (commonStart < commonEnd) {
        printf("Common Time Slot: %02d:%02d - %02d:%02d\n", 
                commonStart / 100, commonStart % 100, 
                commonEnd / 100, commonEnd % 100);
    } else {
        cout << "No common available time.\n";
    }
}

int main() {
    int n;
    cout << "Enter number of participants: ";
    cin >> n;

    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int start, end;
        cout << "Enter time slot for person " << i + 1 << " (HHMM-HHMM): ";
        scanf("%d-%d", &start, &end);
        times.push_back({start, end});
    }

    findCommonTime(times);
    return 0;
}
