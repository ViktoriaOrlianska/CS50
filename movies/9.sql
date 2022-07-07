-- write a SQL query to list the names of all people who starred in a movie released in 2004,
-- ordered by birth year.
-- Eliminate duplicqtes
-- Caefully coount

SELECT  name
FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004
GROUP BY name, person_id
ORDER BY birth;
