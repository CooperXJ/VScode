<!DOCTYPE html>
<html>
<head>
    <title>考勤系统</title>
<style>
        .pg_header{
            position: fixed;
            height: 48px;
            top: 0;
            left: 0;
            right: 0;
            background-color: #2459a2; 
            line-height: 48px;
        }
        .pg_header .logo{
            margin: 0 auto;
            float: left;
            width: 200px;
            text-align: center;
            line-height: 48px;
            font-size: 28px;
            color: white;
        }
        .pg_dl{
            left: 400px;
            display: inline-block;
            padding: 0 40px;
            color: white;
        }
        .pg_header .pg_dl:hover{
            background-color: #2459fb;
            cursor: pointer;
        }
        .left{
            margin-top: 20px;
            width: 400px;
            display: inline-block;
            float: left;        
        }
        .pg_body{
            margin-top: 50px;
            font-size: 18px;
            display: inline-block;
            width: 300px;
        }
        .pg_body .menu{
            width: 800px;
            padding: 15px;    
            float: left;
            font-weight: bold;
        }
        
        textarea{
            width: 200px;
            height: 25px;
            border-radius: 6px;
        }
        
        input[type="text"]{
            width: 200px;
            height: 25px;
            border-radius: 6px;
        }
        input[type="date"]{
            width: 200px;
            height: 25px;
            border-radius: 6px;
        }
        input[type = "radio"]{
            width: 80px;
            height: 23px;
            border-radius: 3px;
        }
        input[type="button"]{
            background-color:#555555;
               border: none;
            color: white;
            padding: 12px 29px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 17px;
            margin: 4px 2px;
            cursor: pointer;
            border-radius: 4px;
            box-shadow:-1px -2px -2px 0 #615959
        }
        input[type="submit"]{
            background-color:orange;
               border: none;
            color: white;
            padding: 12px 29px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 17px;
            margin: 4px 2px;
            cursor: pointer;
            border-radius: 3px;
            box-shadow:-1px -2px -2px 0 #615959 
        }
        input[type="reset"]{
            background-color:orange;
               border: none;
            color: white;
            padding: 12px 29px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 17px;
            margin: 4px 2px;
            cursor: pointer;
            border-radius: 2px;
            box-shadow:-1px -2px -2px 0 #615959
        }
        .kong{
            margin-top: -54px;
            margin-left: 200px;
            float:left;
            padding: 15px;
        }
        .img{
            width: 50px;
            height: 40px;
        }
        .can{
            width: 1220px;
            height: 40px;
            line-height: 40px;
            margin: 0 auto;
            text-align: center;
            display: inline-block;
        }
        .tian{
            float: right;
            font-size: 21px;
            margin-right: -120px;
            margin-top: -45px;
        }
    </style>
</head>
<body id="i88" background = ".\1.jpg" style=" background-repeat:no-repeat ;background-size:100% 100%; background-attachment: fixed;" >
    <form name="tijiao" method="post" onsubmit="return check_is_null()" action="winford.top" style="margin:300px">
    <div class = "pg_header">
        <a class="pg_dl" id="i77">欢迎您打卡签到</a>
        <a class="pg_dl" id ="timer">00:00:00</a>    
    </div>
    	<div align = "center" ><h1 ><font size = "6">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp考勤系统</font></h1></div>
        <div class="left"></div>
        <div class="pg_body">
                <div class="menu"><font size = "4">员工ID</div>
                    <div class="kong">
                        <input id="ID" type="text" name="ID" placeholder="请输入ID"><span id="div1" class="tian" style="margin-top: 4px"></span>
                    </div>
                <div class="menu">姓名</div>
                    <div class="kong">
                        <input id="name" type="text" name="name" placeholder="请输入姓名" ><span id="div1" class="tian" style="margin-top: 4px"></span>
                    </div>
                <div class = "menu">是否缺勤</div>
                	<div class = "tian">
                		<input id = "check1" name = "check" type = "radio" value = "1">是
                		<input id = "check2" name = "check" type = "radio" value = "2">否
                	</div>
                <div class="menu"><font id = "time_word">缺勤时间</font></div>
                    <div class="kong">
                        <input id="time" type="date" name="time" ><span id="div1" class="tian" style="margin-top: 4px"></span>
                    </div>
                <div class="menu"><font ID = hidden_words>缺勤理由</font></div>
                    <div class="kong">
                        <textarea id="reason" name="reason" placeholder="请输入理由" rows = "2" cols = "50px"></textarea><span id="div1" class="tian" style="margin-top: 4px"></span>
                    </div>
        </div>
        <div class="can">
            <input id="submit" type="submit" name="002" value="提交">
            <p style="width: 200px;display: inline-block;"></p>
            <input id="reset" type="reset" name="004" value="取消">

        </div>
        
        <br>
        <br><br>
        <input type = "button" name = "button" id = "button1" value = "增加员工" onclick = "add()">
        <p style="width: 900px;display: inline-block;"></p>
        <input type = "button" name = "button" id = "button2" value = "缺勤记录" onclick = "window.location.href = 'seek.php'">  
    </form>
   
	<script type="text/javascript">
	function check_is_null()
	{	
		var warning = "";
		if(document.getElementById("name").value =="")
		{
			warning += " ID";
		}
		

		if(document.getElementById("ID").value=="")
		{
			warning += " 姓名";
		}
		
		if(warning!="")
		{
			alert("请填写你的"+warning);
			return false;
		}
		return true;
	}

	function check_radio()
	{
		var value ="2";
		var radio = document.getElementsByName("check");
		for(var i = 0;i<radio.length;i++)
		{
			if(radio[i].checked==true)
			{
				value = radio[i].value;
				break;
			}
		}

		var write = document.getElementById("reason");
		var words = document.getElementById("hidden_words");
		var time = document.getElementById("time");
		var time_word = document.getElementById("time_word");
		if(value==1)
		{
			write.style.display = "block";
			words.style.display = "block";
			time.style.display = "block";
			time_word.style.display = "block";
		}

		else
		{
			write.style.display = "none";
			words.style.display = "none";
			time.style.display = "none";
			time_word.style.display = "none";
		}
	}

	setInterval("check_radio()",1);

	function add()
	{
		window.location.href = "4.php"
	}

	function setTime()
	{
		var now = new Date();
		timer.innerHTML = now.getHours()+":"+now.getMinutes()+":"+now.getSeconds()
	}

	setInterval("setTime()",1000);
	</script>
</body>
</html>