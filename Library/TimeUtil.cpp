#include "TimeUtil.h"


TimeUtil::TimeUtil()
{
}


TimeUtil::~TimeUtil()
{
}

void TimeUtil::TimeToString(time_t time1, char *szTime)
{
	struct tm *tm1;
	tm1 = localtime(&time1);
	sprintf(szTime, "%4.4d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d",
		tm1->tm_year + 1900, tm1->tm_mon + 1, tm1->tm_mday,
		tm1->tm_hour, tm1->tm_min, tm1->tm_sec);
}


//ָ��YYYYMMDDHH24MISS�͵�ʱ�䣬��ʽ��Ϊtime_t�͵�ʱ��  
time_t TimeUtil::StringToTime(char * szTime)
{
// 	struct tm tm1;
 	time_t time1 = NULL;
// 
// 
// 	sscanf(szTime, "%4d%2d%2d%2d%2d%2d",
// 		&tm1.tm_year,
// 		&tm1.tm_mon,
// 		&tm1.tm_mday,
// 		&tm1.tm_hour,
// 		&tm1.tm_min,
// 		&tm1.tm_sec);
// 
// 	tm1.tm_year -= 1900;
// 	tm1.tm_mon--;


// 	tm1.tm_isdst = -1;
// 
// 	time1 = mktime(&tm1);
	return time1;
}