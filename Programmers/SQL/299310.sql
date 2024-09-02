WITH MAX_PER_YEAR AS (
    SELECT YEAR(DIFFERENTIATION_DATE) AS YEAR, MAX(SIZE_OF_COLONY) AS MAX_SIZE
    FROM ECOLI_DATA
    GROUP BY YEAR(DIFFERENTIATION_DATE)
)
SELECT
    YEAR(D.DIFFERENTIATION_DATE) AS YEAR,
    MAX_PER_YEAR.MAX_SIZE - D.SIZE_OF_COLONY AS YEAR_DEV,
    D.ID
FROM
    ECOLI_DATA AS D
    JOIN MAX_PER_YEAR
        ON YEAR(D.DIFFERENTIATION_DATE) = MAX_PER_YEAR.YEAR
ORDER BY YEAR ASC, YEAR_DEV ASC