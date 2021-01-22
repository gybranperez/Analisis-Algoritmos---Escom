FROM node:13.3.0 AS compile-image    
COPY package.json package-lock.json ./    
RUN npm install && mkdir /angular-app
ENV PATH="./node_modules/.bin:$PATH"
WORKDIR /angular-app
COPY . .
RUN ng build --prod
FROM nginx
RUN rm -rf /usr/share/nginx/html/*
COPY --from=compile-image /proyecto/dist /usr/share/nginx/html