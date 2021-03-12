# How to Translate English into Propositional Logic
A proposition (simply saying a simple sentence) is either true(1) OR false (0)

```
The sky is blue during a cloudless day.
2 + 2 = 4.
The sun is a moon
```
Each proposition is given a capital letter to represent it
```
Char|    Proposition                               |Value|
S   | The sky is blue during a cloudless day       |  1  |
A   | 2 + 2 = 4                                    |  1  |
M   | The sun is a moon                            |  0  |
```

So, Question: What is not a Proposition? A sentence that cannot be true or false is Not a proposition.
eg, a question, command.

We can modify or conjoin propositions with connectives.

~P          Not P (idk how to type that sign in md) (-|P, P-bar, P' are some other notations)
P^Q         P AND Q
PvQ         P OR  Q
P -> Q      if P then Q
P<->Q       P if and only if Q

## Negation (~) is a unary operator meaning "NOT".

S    Steve will marry a loving person.
~S    Steve won't marry a loving person.
~S    It is not true that Steve will marry a loving person.

How can we symbolize "Dogs are not people" ?
We need an assertive sentence D = "Dog's are people".
Then ~D is out answer.

## Conjunction (^) is a binary operator meaning "AND"  P^Q  P&Q  P.Q
in english, some synnonyms of and are 'even though', 'although', 'because'(in some cases)...

Stacy loves milk and Diccer loves chocolate.            S^D
I went to store even though the store was closed.       S^C
Although Ben is tired, he still wakes up in time for school.    T^W
Both Azad and Omer were able to cook delicious meal.             A^O

## Is this a conjunction?
"Tracy and Karla are sisters"  *NO* cz This is only one simple sentence.
("Tracy is a sister and Karla is a sister" doesnot sould like "Tracy and Karla are sisters")

## Disjunction (v) is a Binary operator meaning "OR"  PvQ  P+Q

Either I leave OR you leave.                                I v Y
I will leave unless you leave.                              I v Y
Tracy likes rabbits or she does not like rabbits.           T v ~T
Neither Bill nor Ben found the hidden amulet.       ~Bi ^ ~Be        ~(Bi v Be)

## Conditional (->)  P -> Q
The conditional is binary opetator meaning "if ... then ..."
              antecedent -> consequent

antecedent: This has to happen
consequent: what happens if the antecedent is true

If you leave, I won't be happy.                  Y -> ~H
The sky will turn red if there is a lot of smoke. (s) smoke -> (r) red
We will dance provided that you learn some dance moves.  (L) learn -> (D) dance
The pencil will run out of lead when you finish your paper.   W (when you finish) -> L (lead)

## Biconditional (<-->) is a binary operator meaning if and only if
P <-> Q = (P->Q) ^ (Q->P)

You will become rich if and only if you get lucky and work hard. R <-> (L ^ W)

Being an even number is necessary and sufficient condition for being divisible by 2.   E <--> D
I will bring an umbrella when and only when it rains.   U <--> R