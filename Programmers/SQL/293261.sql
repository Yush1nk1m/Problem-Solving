SELECT F.ID, N.FISH_NAME, F.LENGTH
FROM FISH_INFO AS F
    JOIN FISH_NAME_INFO AS N
        ON F.FISH_TYPE = N.FISH_TYPE
WHERE LENGTH = (
    SELECT MAX(LENGTH)
    FROM FISH_INFO
    WHERE FISH_TYPE = F.FISH_TYPE
)
ORDER BY F.ID ASC