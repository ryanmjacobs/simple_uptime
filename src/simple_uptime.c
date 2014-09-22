/**
 * @file     simple_uptime.c
 * @version  1.2
 * @brief    Display uptime as: N days, HH:MM:SS.\n
 *           Ex: 1 day, 02:34:56
 *
 * @detail
 *           Mainly useful for getting uptime in seconds resolution.\n
 *           And, it's 0.001s faster than the default command!
 *
 * @author   Ryan Jacobs <ryan.mjacobs@gmail.com>
 * @date     September 22, 2014
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

/* Function Prototypes */
long int get_uptime(void);
struct Time seconds_to_Time(long int seconds);

/* Main Program */
int main(void) {
    struct Time u = seconds_to_Time(get_uptime());

    if (u.days == 1)
        printf("%u day, %02u:%02u:%02u\n",  u.days, u.hours, u.minutes, u.seconds);
    else
        printf("%u days, %02u:%02u:%02u\n", u.days, u.hours, u.minutes, u.seconds);

    return 0;
}

struct Time seconds_to_Time(long int seconds) {
    struct Time t;
    long int remainder;

    t.days     = seconds / (60 * 60 * 24);
    remainder  = seconds % (60 * 60 * 24);

    t.hours    = remainder / (60 * 60);
    remainder  = remainder % (60 * 60);

    t.minutes  = remainder / 60;
    t.seconds  = remainder % 60;

    return t;
}

long int get_uptime(void) {
    struct sysinfo s_info;

    if (sysinfo(&s_info) == -1) {
        perror("Error: sysinfo");
        return 0; // not success, but 0 seconds of uptime
    }

    return s_info.uptime;
}
