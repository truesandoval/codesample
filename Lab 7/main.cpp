#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
struct dayType
{
    int hours[24];
    string date;
};
int Get_Year();
int Get_Starting_Day();
int Read_Num_Days();
int Print_Month(int, int, int, string, dayType[][7][12]);
void Print_Heading();
string Read_Month_Name();
ifstream myfile;
int main() {
    int year1, start_day, number_of_days;
    string month_name;
    myfile.open("/Users/truesandervol/Desktop/Lab 7/Lab 7/infile.txt");
    dayType Year[5][7][12];
    for(int month_counter = 0; month_counter < 12; month_counter++)
        for(int day_counter = 0; day_counter < 7; day_counter++)
            for(int week_counter = 0; week_counter < 5; week_counter++)
            {
                for(int hours_counter = 0; hours_counter < 24; hours_counter++)
                {
                    Year[week_counter][day_counter][month_counter].hours[hours_counter] = 0;
                }
                Year[week_counter][day_counter][month_counter].date = "";
            }
    year1 = Get_Year();
    start_day = Get_Starting_Day();
    for(int l = 0; l < 12; l++){
        month_name = Read_Month_Name();
        number_of_days = Read_Num_Days();
        start_day = Print_Month(start_day, number_of_days, year1, month_name, Year);
    }
    return 0;
}

int Get_Year(){
    int year;
    cout << "Enter the year: " << endl;
    cin >> year;
    return year;
}

int Get_Starting_Day(){
    int day;
    cout << "Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat): " << endl;
    cin >> day;
    return day;
}

void Print_heading(){
    int year;
    year = Get_Year();
    cout << "YEAR -- " << year << endl;
}

string Read_Month_Name(){
    string month_name;
    myfile >> month_name;
    return month_name;
}

int Read_Num_Days(){
    int num_days;
    myfile >> num_days;
    return num_days;
}

int Print_Month(int start_day, int number_of_days, int year1, string month_name, dayType Year[][7][12]){
    cout << setw(24) << month_name << endl;
    cout << setw(8) << "Sun: " << setw(8) << "Mon: " << setw(8) << "Tue: " << setw(8) << "Wed: " << setw(8) << "Thu: " << setw(8) << "Fri: " << setw(8) << "Sat: " << endl;
    for(int counter = 0; counter < start_day; counter++){
        cout << setw(8) << " ";
    }
    for(int i = 1; i <= (number_of_days); i++)
    {
        cout << setw(8) << i;
        if ((start_day + i) % 7 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
    start_day =  (start_day + number_of_days) % 7;
    return start_day;
}

/*
 Enter the year:
 2005
 Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat):
 3
 January
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2       3       4
 5       6       7       8       9      10      11
 12      13      14      15      16      17      18
 19      20      21      22      23      24      25
 26      27      28      29      30      31
 February
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1
 2       3       4       5       6       7       8
 9      10      11      12      13      14      15
 16      17      18      19      20      21      22
 23      24      25      26      27      28
 March
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1
 2       3       4       5       6       7       8
 9      10      11      12      13      14      15
 16      17      18      19      20      21      22
 23      24      25      26      27      28      29
 30      31
 April
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2       3       4       5
 6       7       8       9      10      11      12
 13      14      15      16      17      18      19
 20      21      22      23      24      25      26
 27      28      29      30
 May
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2       3
 4       5       6       7       8       9      10
 11      12      13      14      15      16      17
 18      19      20      21      22      23      24
 25      26      27      28      29      30      31
 
 June
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2       3       4       5       6       7
 8       9      10      11      12      13      14
 15      16      17      18      19      20      21
 22      23      24      25      26      27      28
 29      30
 July
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2       3       4       5
 6       7       8       9      10      11      12
 13      14      15      16      17      18      19
 20      21      22      23      24      25      26
 27      28      29      30      31
 August
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2
 3       4       5       6       7       8       9
 10      11      12      13      14      15      16
 17      18      19      20      21      22      23
 24      25      26      27      28      29      30
 31
 September
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2       3       4       5       6
 7       8       9      10      11      12      13
 14      15      16      17      18      19      20
 21      22      23      24      25      26      27
 28      29      30
 October
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2       3       4
 5       6       7       8       9      10      11
 12      13      14      15      16      17      18
 19      20      21      22      23      24      25
 26      27      28      29      30      31
 November
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1
 2       3       4       5       6       7       8
 9      10      11      12      13      14      15
 16      17      18      19      20      21      22
 23      24      25      26      27      28      29
 30
 December
 Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
 1       2       3       4       5       6
 7       8       9      10      11      12      13
 14      15      16      17      18      19      20
 21      22      23      24      25      26      27
 28      29      30      31
 */
