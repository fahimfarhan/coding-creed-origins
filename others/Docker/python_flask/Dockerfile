FROM python:3.6.6-slim
COPY ./app /app
#CMD ["pip3", "install" , "-r", "requirements.txt"]
RUN pip3 install -r ./app/requirements.txt
#RUN python3 /app/main.py
CMD ["python3","/app/main.py" ]
EXPOSE 5000

