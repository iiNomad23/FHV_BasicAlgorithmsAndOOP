package com.company;

public class Main {

    public static void main(String[] args) {
        Person donald = new Person("Donald", "Duck", 'M', "01.01.1980");
        Person daisy = new Person("Daisy", "Queen", 'F', "10.01.1982");


        System.out.println(donald.isMarriedWith());
        System.out.println(daisy.isMarriedWith());

        donald.marry(daisy);

        System.out.println(donald.isMarriedWith());
        System.out.println(daisy.isMarriedWith());

        daisy.divorce("Not good enough.");

        System.out.println(donald.isMarriedWith());
        System.out.println(daisy.isMarriedWith());
    }
}
