#include <stdio.h>

static const int MONTH_DAYS[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/* CCN = 1 + 1(||) + 1(&&) = 3，计算方法：基础1 + 每个判断分支+1 */
static int is_leap_year(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 1 : 0;
}

/* CCN = 1，计算方法：无分支，圈复杂度为基础值1 */
static int days_of_year(int year)
{
    return 365 + is_leap_year(year);
}

/* CCN = 1 + 1(for) + 1(if) = 3，计算方法：基础1 + for循环+1 + if判断+1 */
static int days_before_month(int year, int month)
{
    int i;
    int total = 0;

    for (i = 1; i < month; i++)
    {
        total += MONTH_DAYS[i];
        if ((i == 2) && (is_leap_year(year) == 1))
        {
            total += 1;
        }
    }

    return total;
}

/* CCN = 1 + 1(for) = 2，计算方法：基础1 + for循环+1 */
static int days_from_base(int year, int month, int day)
{
    int i;
    int total = 0;

    for (i = 1990; i < year; i++)
    {
        total += days_of_year(i);
    }

    total += days_before_month(year, month);
    total += day;

    return total;
}

/* CCN = 1 + 1(if) = 2，计算方法：基础1 + if判断+1 */
int main(void)
{
    int year  = 0;
    int month = 0;
    int day   = 0;
    int week  = 0;
    int total = 0;

    (void)scanf("%d/%d/%d", &year, &month, &day);

    total = days_from_base(year, month, day);
    week  = total % 7;

    if (week != 0)
    {
        (void)printf("%d年%d月%d日是星期%d\n", year, month, day, week);
    }
    else
    {
        (void)printf("%d年%d月%d日是星期日\n", year, month, day);
    }

    return 0;
}