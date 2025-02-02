#include <stdlib.h>
#include <stdio.h>

#include "screen.h"
#include "event.h"
#include "tms.h"
#include "tms/util/list.h"
#include "tms/util/util.h"

#define MAX_EVENTS 1024

#define NUM_CODES 232
const char *codes[NUM_CODES] = {
    "", "", "", "",
    "A", /* 4 */
    "B",
    "C",
    "D",
    "E",
    "F",
    "G", /* 10 */
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q", /* 20 */
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "1", /* 30 */
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "0",
    "ENTER", /* 40 */
    "ESC",
    "BACKSPACE",
    "TAB",
    "SPACE",
    "-",
    "=",
    "[",
    "]",
    "\\", /* 49 */
    "", /* 50 */
    ";", /* 51 */
    "'",
    "`",
    ",",
    ".",
    "/", /* 56 */
    "", /* 57 */
    "F1", /* 58 */
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
    "",
    "SCROLLLOCK",
    "PAUSE",
    "INSERT",
    "HOME",
    "PAGEUP",
    "DELETE",
    "END",
    "PAGEDOWN",
    "RIGHT",
    "LEFT", /* 80 */
    "DOWN",
    "UP", /* 82 */
    "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "MENU", /* 101 */
    "", "", "", "", "", "", "", "", "", "", /* 111 */
    "", "", "", "", "", "", "", "", "", "", /* 121 */
    "", "", "", "", "", "", "", "", "", "", /* 131 */
    "", "", "", "", "", "", "", "", "", "", /* 141 */
    "", "", "", "", "", "", "", "", "", "", /* 151 */
    "", "", "", "", "", "", "", "", "", "", /* 161 */
    "", "", "", "", "", "", "", "", "", "", /* 171 */
    "", "", "", "", "", "", "", "", "", "", /* 181 */
    "", "", "", "", "", "", "", "", "", "", /* 191 */
    "", "", "", "", "", "", "", "", "", "", /* 201 */
    "", "", "", "", "", "", "", "", "", "", /* 211 */
    "", "", "", "", "", "", "", "", "", "", /* 221 */
    "", "",
    "LEFT_CTRL", /* 224 */
    "LEFT_SHIFT",
    "LEFT_ALT",
    "LEFT_META", /* 227 */
    "RIGHT_CTRL", /* 228 */
    "RIGHT_SHIFT", /* 229 */
    "RIGHT_ALT",
    "RIGHT_META", /* 231 */
};

static struct tms_event events[MAX_EVENTS];
static int num_events = 0;

int
tms_event_push(struct tms_event ev)
{
    if (ev.type != -1) {
        if (num_events < MAX_EVENTS) {
            events[num_events++] = ev;
        } else
            tms_errorf("MAX_EVENTS reached");
    }

    return T_OK;
}

int
tms_event_process_all(struct tms_screen *s)
{
    if (s->spec->input) {
        for (int x=0; x<num_events; x++) {
            if (tms_screen_handle_input(s, &events[x], 0) == T_CONT) 
                s->spec->input(s, &events[x], 0);
        }
    }

    num_events = 0;

    return T_OK;
}

