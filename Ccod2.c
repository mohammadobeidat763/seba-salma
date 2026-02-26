#include <unistd.h>
#include <string.h>




void print_msg(const char *msg)
{
    write(1, msg, strlen(msg));
}




void print_num(int n)
{
    char buf[20];
    int i = 0;

    if (n == 0) { write(1, "0", 1); return; }

    while (n > 0) {
        buf[i++] = '0' + (n % 10);
        n /= 10;
    }

    
    for (int j = i - 1; j >= 0; j--)
        write(1, &buf[j], 1);
}




int read_num()
{
    char c;
    int num = 0;
    int valid = 0;

    while (1) {
        read(0, &c, 1);
        if (c == '\n') break;
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            valid = 1;
        } else {
            valid = 0;
        }
    }

    if (!valid) return -1;
    return num;
}




int main()
{
    int grades[100];
    int count = 0;

    if (count <= 0 || count > 100)
    {
        print_msg("ادخل عدد الطلاب (100-1)");
        count = read_num();
    }
    else
    {
        print_msg("خطأ! أدخل رقم بين (100-1) ");
    }


    
    for (int i = 0; i < count; i++) {
        int grade = -1;

        
        if (grade < 0 || grade > 100)
       {
            print_msg("درجة الطالب ");
            print_num(i + 1);
            print_msg(": ");
            grade = read_num();
        }
       else
        {
            print_msg("خطأ! الدرجة بين 0 و 100\n");
        }
        grades[i] = grade;
    }

    
    int sum     = 0;
    int highest = grades[0];
    int lowest  = grades[0];

    for (int i = 0; i < count; i++) {
        sum += grades[i];
        if (grades[i] > highest) highest = grades[i];
        if (grades[i] < lowest)  lowest  = grades[i];
    }

    
    print_msg("\n--- الدرجات ---\n");
    for (int i = 0; i < count; i++) {
        print_msg("الطالب ");
        print_num(i + 1);
        print_msg(": ");
        print_num(grades[i]);
        print_msg("\n");
    }

    
    print_msg("\n--- النتائج ---\n"); 

    print_msg("المتوسط  : ");
    print_num(sum / count);
    print_msg("\n");

    print_msg("الأعلى   : ");
    print_num(highest);
    print_msg("\n");

    print_msg("الأدنى   : ");
    print_num(lowest);
    print_msg("\n");

    return 0;
}