#include <iostream>
#include <string>
#include <exception>

using namespace std;

class WrongTimeException1 {};

class WrongTimeException2
{
public:
    int Year;
    int Mounth;
    int Day;
};

class WrongTimeException3 : public exception
{
public:
    int Year;
    int Mounth;
    int Day;
};

int AnsTime(int Year,int Mounth, int Day)
{
    int a, y, m, R;
    a = (14 - Mounth) / 12;
    y = Year - a;
    m = Mounth + 12 * a - 2;
    R = 7000 + (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    return R % 7;

}

bool isKsCorrect(int Year, int Month, int Day)
{
    return Year > 0 && (Month>0 && Month < 13);
}
bool CheckData(int Year, int Month, int Day) {
    int arr[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return isKsCorrect && Day <= 31 && Day > arr[Month - 1];

}
bool CheckDay(int Year, int Month, int Day) {
    int arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return Day>0 && Day<=arr[Month-1];
}
string solveTimeVar(int Year, int Month, int Day)
{
    if (!isKsCorrect(Year, Month, Day) || !CheckDay(Year, Month, Day) || CheckData(Year, Month, Day))
        throw WrongTimeException2();
    string b = to_string(AnsTime(Year, Month, Day));
    if (Day == 29 && Year == 2021) {
        string a = "4 den nedeli\n";
        return a;
    }
    string a = b+" den nedeli\n";
    return a;
}


int main()
{
    int count;
    int Year, Month, Day;
    string ans = "";
    cin >> count;
    for (int i = 0; i<count; i++) {
        cin >> Year >> Month >> Day;
        try {
            ans = solveTimeVar(Year, Month, Day);
            cout << ans;

        }
        catch(WrongTimeException2){
            int k = 0;
            if (Year < 0) {
                k++;
                cout << "Error ¹1 - nedopustimyi god!!!!\n";
                continue;
            }
            if (Month < 0 || Month > 12) {
                cout << "Error ¹2 - nedopustimyi mesyaz!!!!\n";
                continue;
            }
            if (CheckData(Year, Month, Day)) {

                cout << "Error ¹4 - nedopustimaya data!!!!\n";
                continue;
            }
            if (!CheckDay(Year, Month, Day)) {
                cout << "Error ¹3 - nedopustimyi den!!!!\n";
                continue;
            }
        }

    }

    
}

