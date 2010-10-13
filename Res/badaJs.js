var msg = document.getElementById('msg');

var shakeStart = function(){
    msg.style.color = "#000";
    msg.style.backgroundColor = "#f0f";
    msg.innerHTML = "SHAKE START";
}

var shakeStop = function(){
    msg.style.color = "#ccc";
    msg.style.backgroundColor = "#00f";
    msg.innerHTML = "SHAKE STOP";
}

var doubleTap = function(){
    msg.style.color = "#ccc";
    msg.style.backgroundColor = "#f00";
    msg.innerHTML = "DOUBLE TAP";
}

var snap = function(e){
    var color, text;
	switch(e){
        case "X+":
            color = "#0ff";
            text = "X POSITIVE SNAP";
            break;
        case "X-":
            color = "#0ff";
            text = "X NEGATIVE SNAP";
            break;
        case "Y+":
            color = "#ff0";
            text = "Y POSITIVE SNAP";
            break;
        case "Y-":
            color = "#ff0";
            text = "Y NEGATIVE SNAP";
            break;
        case "Z+":
            color = "#ccc";
            text = "Z POSITIVE SNAP";
            break;
        case "Z-":
            color = "#ccc";
            text = "Z NEGATIVE SNAP";
            break;
    }
    msg.style.color = "#000";
    msg.style.backgroundColor = color;
    msg.innerHTML = text;
}