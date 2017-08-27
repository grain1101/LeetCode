package com.company;
/* internally above enum Color is converted to
Every enum constant is always implicitly public static final. Since it is static, we can access it by using enum Name. Since it is final, we can’t create child enums.
class Color
{
     public static final Color RED = new Color();
     public static final Color BLUE = new Color();
     public static final Color GREEN = new Color();
}*/
enum Day {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday;
}
public class DayEnum {
    Day day;
    public DayEnum(Day d) {
        this.day = d;
    }
    Day days[] = Day.values();

    public void showDay() {
        System.out.println(Day.valueOf("Monday"));
        for(Day day1 : days) {
            System.out.println(day1.ordinal());
        }
        switch (day) {
            case Monday:
                System.out.println("this is Monday");
                System.out.println(day.ordinal());
                break;
            case Tuesday:
                System.out.println("this is Tuesday");
                System.out.println(day.ordinal());
                break;
            case Wednesday:
                System.out.println("this is Wednesday");
                break;
            case Thursday:
                System.out.println("this is Thursday");
                System.out.println(day.ordinal());
                break;
            case Friday:
                System.out.println("this is Friday");
                break;
            case Saturday:
                System.out.println("this is Saturday");
                break;
            case Sunday:
                System.out.println("this is Sunday");
                break;
            default:
                System.out.println("this is everyday");
                break;
        }
    }
}
