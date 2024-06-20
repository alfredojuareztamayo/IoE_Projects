const char pagina[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta charset='utf-8'/>
    <title>ESP32 Control</title>
    <style>
      body {
        background-color: black;
        color: white;
        font-family: Arial, sans-serif;
        text-align: center;
      }
      h1 {
        margin-top: 50px;
      }
      button {
        height: 50px;
        width: 100px;
        font-size: 16px;
        background-color: white;
        color: black;
        border: none;
        cursor: pointer;
      }
      button:hover {
        background-color: #555;
        color: white;
      }
    </style>
  </head>
  <body>
    <h1>ESP32 Control</h1>
    <p><a href='/on'><button>ON</button></a></p>
    <p><a href='/off'><button>OFF</button></a></p>
  </body>
</html>
)=====";