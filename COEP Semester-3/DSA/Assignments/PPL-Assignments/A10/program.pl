% Define the courses offered by the institute
course(math).
course(english).
course(history).
course(science).


% Define the prerequisites for each course
prerequisite(math, science).
prerequisite(history, english).


% Define the student current courses

student_course(math).
student_course(english).


% Define a rule to determine if a student can take a course

can_take_course(Course) :-
    course(Course),
    \+ student_course(Course),
    \+ (prerequisite(Course, Prereq), \+ student_course(Prereq)).


% Define a rule to enroll a student in a course
enroll_student(Course) :-
    can_take_course(Course),
    assertz(student_course(Course)).
