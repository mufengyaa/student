#include <stdio.h>
/* 1990年1月1日 是星期一 */
void main()
{
    int year, month, day, week, leap;
    int sum = 0;
    int i;
    scanf("%d/%d/%d", &year, &month, &day);
    for (i = 1990; i < year; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
        {
            sum += 366;
        }
        else
        {
            sum += 365;
        }
    }
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        leap = 1;
    }
    else
    {
        leap = 0;
    }
    switch (month - 1)
    {
    case 11:
        sum += 30;
    case 10:
        sum += 31;
    case 9:
        sum += 30;
    case 8:
        sum += 31;
    case 7:
        sum += 31;
    case 6:
        sum += 30;
    case 5:
        sum += 31;
    case 4:
        sum += 30;
    case 3:
        sum += 31;
    case 2:
        sum += 28 + leap;
    case 1:
        sum += 31;
    }
    sum += day;
    week = sum % 7;

    if (week != 0)
    {
        printf("%d年%d月%d日是星期%d\n", year, month, day, week);
    }
    else
    {
        printf("%d年%d月%d日是星期日\n", year, month, day);
    }
} 