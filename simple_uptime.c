/**
 * @file     simple_uptime.c
 * @version  1.1
 * @brief    Display uptime as: N days, HH:MM:SS.\n
 *           Ex: 1 day, 02:34:56
 *
 * @detail
 *           It's useful for people who need an uptime with
 *           seconds. I use it for my dwm statusbar.
 *
 * @author   Ryan Jacobs (ryan.mjacobs@gmail.com)
 * @date     May 06, 2014
 * @bug      No known bugs.
 */

#include <stdio.h>
#include <sys/sysinfo.h>

struct Time {
    unsigned int days;
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};

long int get_uptime(void);
void format_seconds(struct Time *time, long unsigned int seconds);

int main(void) {
    struct Time uptime;

    format_seconds(&uptime, get_uptime());

    if (uptime.days == 1)
        printf("%u day, %02u:%02u:%02u\n", uptime.days, uptime.hours, uptime.minutes, uptime.seconds);
    else
        printf("%u days, %02u:%02u:%02u\n", uptime.days, uptime.hours, uptime.minutes, uptime.seconds);

    return 0;
}

void format_seconds(struct Time *time, long unsigned int seconds) {
    long int remainder;

    time->days    = seconds / (60 * 60 * 24);
    remainder     = seconds % (60 * 60 * 24);

    time->hours   = remainder / (60 * 60);
    remainder     = remainder % (60 * 60);

    time->minutes = remainder / 60;
    time->seconds = remainder % 60;
}

long int get_uptime(void) {
    int error;
    struct sysinfo s_info;

    error = sysinfo(&s_info);

    if(error != 0)
        printf("Error reading sysinfo. Error code: %d\n", error);
    return s_info.uptime;
}
