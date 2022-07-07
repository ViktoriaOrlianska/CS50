-- write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

-- Write a query to find all movies which JD has starred
-- Write a query to find all movies which HBC has starred
-- take intersection

SELECT title
FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id
WHERE name = "Johnny Depp"
INTERSECT
SELECT title
FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id
WHERE name = "Helena Bonham Carter"
