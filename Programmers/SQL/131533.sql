SELECT P.PRODUCT_CODE, SUM(P.PRICE * S.SALES_AMOUNT) AS SALES
FROM PRODUCT AS P
    JOIN OFFLINE_SALE AS S
        ON S.PRODUCT_ID = P.PRODUCT_ID
GROUP BY P.PRODUCT_CODE
ORDER BY SALES DESC, P.PRODUCT_CODE ASC