/*
** EPITECH PROJECT, 2019
** test_my_bsq.c
** File description:
** test bsq
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int bsq(char *file);

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

char *init_str(char *file)
{
    struct stat sb;
    int fd = open(file, O_RDONLY);
    char *str;
    int size = 0;

    stat(file, &sb);
    size = sb.st_size;
    str = malloc(sizeof(char) * (size + 1));
    read(fd, str, size);
    str[size] = '\0';
    return (str);
}

Test(bsq, test_one, .init = redirect_stdout)
{
    char *str = init_str("tests/mouli_maps_solved/intermediate_map_100_100");

    bsq("tests/mouli_maps/intermediate_map_100_100");
    cr_assert_stdout_eq_str(str);
}

Test(bsq, test_two)
{
    cr_assert_eq(bsq("tests/mouli_maps/error1"), 84);
}

Test(bsq, test_three)
{
    cr_assert_eq(bsq("tests/mouli_maps/lol"), 84);
}

Test(bsq, test_four)
{
    cr_assert_eq(bsq("tests/mouli_maps/include"), 84);
}

Test(bsq, test_five)
{
    cr_assert_eq(bsq("tests/mouli_maps/error3"), 84);
}

Test(bsq, test_six)
{
    cr_assert_eq(bsq("tests/mouli_maps/error4"), 84);
}

Test(bsq, test_seven)
{
    cr_assert_eq(bsq("tests/mouli_maps/error5"), 84);
}

Test(bsq, test_eight)
{
    cr_assert_eq(bsq("tests/mouli_maps/error6"), 84);
}

Test(bsq, test_nine, .init = redirect_stdout)
{
    char *str = init_str("tests/mouli_maps_solved/intermediate_map_200_200");

    bsq("tests/mouli_maps/intermediate_map_200_200");
    cr_assert_stdout_eq_str(str);
}
