// 不适用平均数，改用homework的中位数-->计算未知数量的数据的中位数。
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
int main() {
    cout << "Please enter yoiur first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    cout << "Please enter your mideerm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    cout << "Enter all your homework grades,"
            "followed by end-of-file: ";
    double x;
    vector<double> homework;
    while (cin >> x)
        homework.push_back(x);
    // 类似std::string::size_type
    typedef vector<double>::size_type vec_sz;
    // 两个size的scope不同，前者是{}中的local scope，
    // 后者是class scope，所以不会冲突。
    vec_sz size = homework.size();
    if (size == 0) {
        cout << endl
             << "You must enter your grades. "
                "Please try again. "
             << endl;
        return 1;
    }
    sort(homework.begin(), homework.end());
    vec_sz mid = size / 2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;
    return 0;
}