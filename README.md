# DSBA Introduction to Programming // Workshop 29

Spring semester 2021/22

Pointers. Inheritance.

# Tasks

## Task 1. Student.

Add a class `Student` similar to classes `Passenger` and `Citizen`. Aside from name and age a `Student` should contain a field `university` (a random string). It should be inherited from `Person` and should work together with all other code in the example.

## Task 2. Virtual.

Make a function `void capitalize(Person* p)` that works for all four classes and capitalizes all their fields that contains strings.

See the implementation of `operator <<` for hints how to implement this function. Use virtual methods.

Add this function to the user input loop in `main()`.

## Task 3. Custom container.

Make a class `PersonRegistry` which stores a vector of `Person*` pointers and has methods `addPerson`, `addPassenger`, `addCitizen`, `addStudent`.

**Goal**: change the code in `main` so that you only use methods of `PersonRegistry` and the user input.

In particular:

- Use the existing code in `main` for implementation of methods.
- Overload `operator[]` to access elements by their index.
- Add a destructor `~PersonRegistry()` that deletes all data when the registry is destroyed (using `delete`);
- Add a method `print` that prints all elements.
