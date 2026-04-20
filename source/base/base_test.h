/* base library internal error checking system */
#ifndef BASE_ERROR_H
#define BASE_ERROR_H

#define _stringify(x) #x
#define _str(x) _stringify(x)

#define _write(buffer) _os_write(STDERR_FD, (buffer), Len(buffer))

#define error_at(msg)                                                   \
    do {                                                                \
        _write(Red "[ERROR] " __FILE__ ":" _str(__LINE__) ":");    \
        _write(__func__);                                              \
        _write(": " Reset);                                            \
        _write((msg));                                                 \
        _write("\n");                                                  \
    } while (0)

#define warn(msg)                                                       \
    do {                                                                \
        _write(Yellow "[WARN] " __FILE__ ":" _str(__LINE__) ":");  \
        _write(__func__);                                              \
        _write(": " Reset);                                            \
        _write((msg));                                                 \
        _write("\n");                                                  \
    } while (0)

#define assert_msg(expr, msg)                                           \
    do {                                                                \
        if (!(expr)) {                                                  \
            _write(Red "[ASSERT] " __FILE__ ":" _str(__LINE__) ":"); \
            _write(__func__);                                          \
            _write(": " Reset);                                        \
            _write((msg));                                             \
            _write("\n");                                              \
            _exit(1);                                                  \
        }                                                               \
    } while (0)

#define test(expr)                                                      \
    do {                                                                \
        if ((expr) != 0) {                                              \
            _write(Red "[FAILED] " __FILE__ ":" _str(__LINE__) ":"); \
            _write(__func__);                                          \
            _write(Reset "\n");                                        \
            _exit(1);                                                  \
        }                                                               \
    } while (0)

#endif /* BASE_ERROR_H */
