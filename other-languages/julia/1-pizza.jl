# Pizza Slices
# Let's try this out on a problem. Let's say you want to order pizzas for 10 people (people = 10) and each person wants 2.5 slices on average (avg = 2.5). A pizza has 8 slices per pizza (slices = 8). How many pizzas should you order (pizzas = ?)? So we have the following

# Meaning	Variable
# Number of people	people
# Average number of slices each person eats	avg
# Number of slices on a piece of pizza	slices

people = 10;
avg = 2.5;
slices = 8;

pizzas = people * avg / slices;

println(pizzas);

pizzasRounded = ceil(pizzas);

println(pizzasRounded);