    #include <iostream>
    #include <string>
    using namespace std;

    #pragma warning(disable : 4996)

    enum enCompareDate { Before = -1, Equal = 0, After = 1 };

    struct stDate
    {
        int day = 0;
        int month = 0;
        int year = 0;
    };
    struct stPeriod
    {
        stDate StartDate;
        stDate EndDate;
    };

    int ReadNumber(string M)
    {
        int Number;
        cout << M;
        cin >> Number;
        return Number;
    }

    stDate ReadFullDate()
    {
        stDate Date;

        Date.day = ReadNumber("\nPlease enter a Day? ");
        Date.month = ReadNumber("Please enter a Month? ");
        Date.year = ReadNumber("Please enter a Year? ");

        return Date;
    }

    stPeriod ReadPeriod()
    {
        stPeriod Period;
        cout << "\nEnter Start Date:\n";
        Period.StartDate = ReadFullDate();
        cout << "\nEnter End Date:\n";
        Period.EndDate = ReadFullDate();

        return Period;
    }

    bool IsLeapYearOrNot(int year)
    {
        return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    }

    int HowManyDaysInMonth(int nYear, int nMonth)
    {
        if (nMonth < 1 || nMonth>12)
            return 0;

        int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        return (nMonth == 2) ? (IsLeapYearOrNot(nYear) ? 29 : 28) : NumberOfDays[nMonth - 1];

    }

    bool IsLastDayInMonth(stDate Date)
    {
        return (Date.day == HowManyDaysInMonth(Date.year, Date.month));
    }

    bool IsLastMonthInYear(short month)
    {
        return (month == 12);
    }

    stDate IncreaseDateByOneDay(stDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.month))
            {
                Date.month = 1;
                Date.day = 1;
                Date.year++;
            }
            else
            {
                Date.day = 1;
                Date.month++;
            }
        }
        else
        {
            Date.day++;
        }
        return Date;
    }

    bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
    {
        return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ?
            (Date1.month < Date2.month ? true : (Date1.month == Date2.month ?
                Date1.day < Date2.day : false)) : false);
    }

    int DiffrenceDays2Dates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;

        while (IsDate1LessThanDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);

        }

        return (IncludeEndDay) ? ++Days : Days;

    }

    bool IsDate1EqualDate2(stDate Date1, stDate Date2)
    {
        if (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day == Date2.day)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    int PeriodLength(stPeriod Period1, bool IncludeEndDay = false)
    {
        return DiffrenceDays2Dates(Period1.StartDate, Period1.EndDate, IncludeEndDay);
    }


    enCompareDate CompareDate(stDate Date1, stDate Date2)
    {
        if (IsDate1EqualDate2(Date1, Date2))
        {
            return enCompareDate::Equal;
        }
        else if (IsDate1LessThanDate2(Date1, Date2))
        {
            return enCompareDate::Before;
        }
        else
        {
            return enCompareDate::After;
        }

    }

    bool IsDateWithInPeriod(stPeriod Period1, stDate Date2)
    {
        return !(CompareDate(Date2, Period1.StartDate) == enCompareDate::Before
            || CompareDate(Date2, Period1.EndDate) == enCompareDate::After);
    }


    void PrintResults()
    {
        cout << "\nEnter Period 1:";
        stPeriod Period1 = ReadPeriod();
    
        cout << "Enter Date to check: " << endl << endl;
        stDate Date2 = ReadFullDate();


        if (IsDateWithInPeriod(Period1, Date2))
        {
            cout << "\nYes,Date is within period";
        }
        else
        {
            cout << "\nNo, Date is not within period.";
        }

    }

    int main()
    {
        PrintResults();

        return 0;
    }
