function clickEmoji(e) { 
	var xo = 6; var yo = 6; var xs = 26; var ys = 24;
	var x = e.offsetX; 
	var y = e.offsetY;
	var c = Math.round((x - xo - 4) / xs); 
	var r = Math.round((y - yo - 4) / ys); 
	document.getElementById('out').innerText = 'Selected [' + (c + 1) + ', ' + (r + 1) + ']'; 
	var img = document.getElementById('emojis'); 
	var ce = document.getElementById('emoji'); var ctx = ce.getContext('2d'); 
	ctx.drawImage(img, -(xo + (xs * c)), -(yo + (ys * r)), 262, 244); 
	var index = 'p' + c + '' + r; console.log('index: ' + index); 
	ws.send(index); 
}


function changeMode(num) { 
	var modelNum = 'm' + parseInt(num).toString(16); 
	console.log('Model: ' + modelNum); 
	ws.send(modelNum);
}


function GameMode(num) { 
	var modelNum = 'g' + parseInt(num).toString(16); 
	ws.send(modelNum);
}

function T_PlayMode(num) { 
	var modelNum = 'T' + parseInt(num).toString(16); 
	console.log('Model: ' + modelNum); 
	ws.send(modelNum);
}



function sendBrightness() { 
	var Obrightness = document.getElementById('bt').value; 
	var oMessage = 's'; 
	if (Obrightness.length == 1) { 
		oMessage = oMessage + '00'; 
	} else if (Obrightness.length == 2) { 
		oMessage = oMessage + '0'; 
	} 
	document.getElementById('bt_value').value=parseInt(Obrightness ? Obrightness : 999);
	oMessage = oMessage + parseInt(Obrightness ? Obrightness : 999); 
	console.log('oMessage: ' + oMessage); ws.send(oMessage); 
}

function sendHue(n) { 
	var OHueValue = document.getElementById('hue'+n).value; 
	var oMessage = 'h'+n; 
	if (OHueValue.length == 1) { 
		oMessage = oMessage + '00'; 
	} else if (OHueValue.length == 2) { 
		oMessage = oMessage + '0'; 
	} 
	if(n=='a'){
		var els =document.getElementsByName('hue_value');
		for (var i = 0, j = els.length; i < j; i++){
			els[i].value = OHueValue;
		}
	}else{
		document.getElementById('hue'+n+'_value').value=parseInt(OHueValue ? OHueValue : 360);
	}
	oMessage = oMessage + parseInt(OHueValue ? OHueValue : 999); 
	console.log('oMessage: ' + oMessage); ws.send(oMessage); 
}

function configSave() {
	var oMessage = 'c'; 
	console.log('oMessage: ' + oMessage); ws.send(oMessage); 
}

function keySave() {
	let city = document.getElementById('city_value').value;
	let key = document.getElementById('yy_key_value').value;
	let oMessage = {
		city: city,
		key: key
	}; 
	console.log('oMessage: ' + JSON.stringify(oMessage));
	ws.send(JSON.stringify(oMessage)); 
}


function clockMode(num) {
	var styleNum = 't' + parseInt(num).toString(16);
	console.log('时钟风格: ' + styleNum); 
	ws.send(styleNum);
}

function DateModel(num) {
	var styleNum = 'd' + parseInt(num).toString(16);
	console.log('日期风格: ' + styleNum); 
	ws.send(styleNum);
}

function LoopModel(num) {
	var styleNum = 'l' + parseInt(num).toString(16);
	console.log('切换风格: ' + styleNum); 
	ws.send(styleNum);
}

function BFansModel(num) {
	var styleNum = 'b' + parseInt(num).toString(16);
	console.log('粉丝数风格: ' + styleNum); 
	ws.send(styleNum);
}



function BTNup(){
 
	ws.send('U');
}

function BTNdown(){

	ws.send('D');
}

function BTNleft(){
	ws.send('L');
}

function BTNright(){
	ws.send('R');
}

function BTNstart(){
	ws.send('S');
}

function BTNpause(){
	ws.send('P');
}

function Clear(){
	console.log('傳送: K'); 
	ws.send('K');
}

function sendrandomcolor(){

	ws.send('Z');
}


function randomGIF(){
	console.log('傳送: V'); 
	ws.send('V');
}

function playGIF() {
	let GIF = document.getElementById('GIFname_value').value;
	let oMessage = {
		GIFname: GIF,
	}; 
	console.log('oMessage: ' + JSON.stringify(oMessage));
	ws.send(JSON.stringify(oMessage));
	ws.send('H');
}


function timeGIFname() {
	let GIF = document.getElementById('GIFname_value').value;
	let oMessage = {
		GIFname: GIF,
	}; 
	
	if(GIF != 'null' && GIF != ''){
	mui.toast('已設定:'+GIF);
	console.log('oMessage: ' + JSON.stringify(oMessage));
	ws.send(JSON.stringify(oMessage)); 
	ws.send('J');
				}else{
					mui.toast('檔名不能為空');
				}
}



function textSend(){
		
				var inputText = $('#input_value').val();
				var oMessage = {
		                    InputText: inputText,
	                     }; 
	                     
				if(inputText != 'null' && inputText != ''){

				  ws.send(JSON.stringify(oMessage)); 
					//ws.send(inputText);
					mui.toast('已發送:'+inputText);
				}else{
					mui.toast('文字不能為空');
				}
			}
			
			
			
function WIFISend(){
		
				var SSID = $('#input_SSID').val();
				var PASSWORD = $('#input_PASSWORD').val();
				var oMessage = {
		                    SSID: SSID,
		                    PASSWORD: PASSWORD
	                     }; 
	                     
				if(SSID != 'null' && SSID != '' && PASSWORD != 'null' && PASSWORD != ''){

				  ws.send(JSON.stringify(oMessage)); 
					ws.send('W');
					mui.toast('設定完成,4秒後重開機');
				}else{
					mui.toast('輸入不能為空');
				}
			}			
			
			
			