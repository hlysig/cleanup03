FROM postgis/postgis
ENV POSTGRES_USER "object"
ENV POSTGRES_PASSWORD "object"
ENV POSTGRES_DB "objectcube"

WORKDIR /docker-entrypoint-initdb.d
ADD schema.sql /docker-entrypoint-initdb.d
EXPOSE 5432
