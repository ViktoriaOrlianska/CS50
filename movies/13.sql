-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred

-- 1. First find Kevin Bacon(name = "KB" and birt = '')
-- 2. Find the movie_ids which Kevin Bacon has starred
-- 3. Movie_id | Person_id | person name
--    ----------------------------------
--      10              5.    Kevin Bacon
--      30              5.    Kevin Bacon
--      50              5.    Kevin Bacon
--      12              5.    Kevin Bacon


-- Be sure to only select the Kevin Bacon born in 1958.
-- movie_id | person_id.  | name
--   10          1        |. Dwayne
--   12          5        |. Kevin Bacon
--   15          100      |  Tom

SELECT DISTINCT name
FROM stars JOIN people ON stars.person_id = people.id
WHERE movie_id IN
(SELECT movie_id
FROM people JOIN stars ON stars.person_id = people.id
WHERE birth = 1958 and name = "Kevin Bacon")
AND name != "Kevin Bacon";
