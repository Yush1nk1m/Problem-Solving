SELECT MEMBER_NAME, REVIEW_TEXT, DATE_FORMAT(REVIEW_DATE, "%Y-%m-%d") AS REVIEW_DATE
FROM REST_REVIEW AS R
    JOIN MEMBER_PROFILE AS P
        ON R.MEMBER_ID = P.MEMBER_ID
    JOIN (
        SELECT MEMBER_ID
        FROM REST_REVIEW
        GROUP BY MEMBER_ID
        ORDER BY COUNT(*) DESC
        LIMIT 1
    ) AS C
        ON R.MEMBER_ID = C.MEMBER_ID
ORDER BY REVIEW_DATE ASC, REVIEW_TEXT ASC