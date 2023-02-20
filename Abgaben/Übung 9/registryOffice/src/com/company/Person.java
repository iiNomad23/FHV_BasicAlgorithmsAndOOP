package com.company;

import java.time.DateTimeException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Arrays;

/**
 * The class describes a person with some methods and properties.
 * You can marry and divorce two persons.
 *
 * @author Marco Prescher
 */

public class Person {
    private String firstName;
    private String lastName;
    private String birthName;
    private char gender;

    private LocalDate birthday;
    private Person myPrecious;

    public Person(String firstName, String lastName, char gender, String birthday) {
        if (firstName == null || lastName == null || birthday == null) {
            System.out.println("Please enter valid parameters");
            return;
        }

        if (gender != 'M' && gender != 'F') {
            System.out.println("Please enter valid genders");
            return;
        }

        this.firstName = firstName;
        this.lastName = this.birthName = lastName;
        this.gender = gender;

        try {
            this.birthday = LocalDate.parse(birthday, DateTimeFormatter.ofPattern("dd.MM.yyyy"));
        } catch (DateTimeException e) {
            System.out.println(Arrays.toString(e.getStackTrace()));
        }

        if (this.birthday == null) {
            System.out.println("Please give the person a proper birthDate.");
        }
    }

    // getter/setter ---------------------------------------------------------------------------------------------------------------
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getBirthName() {
        return birthName;
    }

    public char getGender() {
        return gender;
    }

    public LocalDate getBirthday() {
        return birthday;
    }

    public Person getMyPrecious() {
        return myPrecious;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    private void setBirthName(String birthName) {
        this.birthName = birthName;
    }

    public void setGender(char gender) {
        this.gender = gender;
    }

    public void setBirthday(LocalDate birthday) {
        this.birthday = birthday;
    }

    private void setMyPrecious(Person myPrecious) {
        this.myPrecious = myPrecious;
    }

    // functions -------------------------------------------------------------------------------------------------------------------
    private boolean isOlderThan18() {
        return this.birthday.plusYears(18).minusDays(1).isBefore(LocalDate.now());
    }

    public void marry(Person person) {
        if (this.isOlderThan18() && person.isOlderThan18()) {
            String marryPersonsFirstName = person.getFirstName();

            System.out.println("\n" + this.firstName + " want to marry " + marryPersonsFirstName);

            this.setMyPrecious(person);
            this.setLastName(person.getLastName());

            person.setMyPrecious(this);
            System.out.println(this.firstName + " and " + marryPersonsFirstName + " are now married.\nYour life's has come to an end.\n");
        } else {
            System.out.println("\nPersons are below 18 years. NoNoNo.\n");
        }
    }

    public void divorce(String reason) {
        if (reason != null && !reason.equals("")) {
            System.out.println("\n" + this.firstName + " want a divorce.");
            Person person = this.myPrecious;

            System.out.println(this.firstName + " and " + person.getFirstName() + " are now divorced.\nReason: " + reason + "\nParty on!\n");

            person.setMyPrecious(null);
            person.setLastName(person.getBirthName());

            this.myPrecious = null;
            this.lastName = this.birthName;
        } else {
            System.out.println("\nNo valid reason specified.\n");
        }
    }

    public String isMarriedWith() {
        return this.firstName + " is married with: " + (this.myPrecious == null ? "Nobody - Forever alone." : (this.myPrecious.getFirstName() + " " + this.myPrecious.getLastName()));
    }
}
