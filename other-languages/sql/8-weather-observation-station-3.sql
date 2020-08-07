/*
Enter your query here.
*/
SELECT DISTINCT CITY FROM STATION WHERE ( (ID & 1) = 0);