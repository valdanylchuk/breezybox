/*
 * date.c - Show/set date and time
 * 
 * Usage: date ["YYYY-MM-DD HH:MM:SS"]
 */

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int cmd_date(int argc, char **argv)
{
    time_t now;
    struct tm timeinfo;
    
    // Set time if argument provided: date "2025-01-15 20:30:00"
    if (argc >= 2) {
        int y, mon, d, h, m, s;
        if (sscanf(argv[1], "%d-%d-%d %d:%d:%d", &y, &mon, &d, &h, &m, &s) == 6) {
            timeinfo.tm_year = y - 1900;
            timeinfo.tm_mon = mon - 1;
            timeinfo.tm_mday = d;
            timeinfo.tm_hour = h;
            timeinfo.tm_min = m;
            timeinfo.tm_sec = s;
            timeinfo.tm_isdst = 0;
            
            struct timeval tv = { .tv_sec = mktime(&timeinfo), .tv_usec = 0 };
            settimeofday(&tv, NULL);
            printf("Date set.\n");
            return 0;
        } else {
            printf("Usage: date [\"YYYY-MM-DD HH:MM:SS\"]\n");
            return 1;
        }
    }
    
    // Get and display current time
    time(&now);
    localtime_r(&now, &timeinfo);
    
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeinfo);
    printf("%s\n", buf);
    return 0;
}