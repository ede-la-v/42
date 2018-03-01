
      window.onload = function(){

          var phot = document.getElementById("phot");
       var chap = document.getElementById("chap");
          var stache = document.getElementById("stache");
      var cache_div = document.getElementById('cache');

      var cache = document.getElementById('cache').children;
      for (var i = 0; i < cache.length; i++) {
      cache[i].onclick = function(){
      	effet_add = document.getElementsByTagName("Fieldset")[0].getElementsByTagName("img");
        for (var j = 0; j < effet_add.length; j++) {
          effet_add[j].classList.add('hide');
        }
        document.getElementById(this.getAttribute('id').replace('2', '')).classList.remove("hide");
		takefoto.classList.remove("hide");
      }
    }

      var video = document.querySelector('video');
      var canvas = document.querySelector('canvas');
      canvas.width = 640;
		canvas.height = 480;
      var takefoto = document.getElementById('takephoto');

      takefoto.onclick = function() {
        var type = 0;
        var classes_chap = chap.className;
        classes_chap = " "+classes_chap+" ";
        var classes_stache = stache.className;
        classes_stache = " "+classes_stache+" ";
        if (!classes_chap.match(/ hide /))
          type = 1;
        if (!classes_stache.match(/ hide /))
          type = 2;
        canvas.classList.remove("hide");
	  var classes_phot = phot.className;
	  classes_phot = " "+classes_phot+" ";
		if (!classes_phot.match(/ hide /))
		{
        document.querySelector('form').classList.remove('hide');
			canvas.width = phot.offsetWidth;
			canvas.height = phot.offsetHeight;
        	var ctx = canvas.getContext("2d").drawImage(phot, 0, 0, phot.offsetWidth, phot.offsetHeight);
		}
		else
        	var ctx = canvas.getContext("2d").drawImage(video, 0, 0, 640, 480);
        var data = canvas.toDataURL('image/png');
        canvas.classList.add('hide');
        var http = new XMLHttpRequest();
        http.open("POST", "save.php", true);
        http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        http.onreadystatechange = function() {
		  if (this.readyState == 4 && this.status == 200) {
        var n_div = document.createElement("div");
        n_div.setAttribute('class', "row text-center");
        var oImg = document.createElement("img");
        oImg.setAttribute('src', "../images/"+this.responseText+'.png');
        oImg.setAttribute('class', "img-thumbnail");
        n_div.append(oImg);
        l_foto.insertBefore(n_div, l_foto.childNodes[2]);
        
		  }
		  else if (this.readyState == 4)
       	alert(this.responseText);
		};
		
		http.send("img="+encodeURIComponent(data)+"&type="+type);
		      }



	  function findGetParameter(parameterName) {
		  var result = null,
		  tmp = [];
		  location.search
			  .substr(1)
			  .split("&")
			  .forEach(function (item) {
				  tmp = item.split("=");
				  if (tmp[0] === parameterName) result = decodeURIComponent(tmp[1]);
			  });
		  return result;
	  }

	  if (findGetParameter('photo'))
	{
		  cache_div.classList.remove("hide");
		video.classList.add("hide");
		
		phot.classList.remove("hide");
          var chap = document.getElementById("chap");
          var stache = document.getElementById("stache");
          phot_width = phot.offsetWidth;
          chap.style.width = (phot_width/640)*200+"px";
          chap.style.height = (phot_width/640)*170+"px";
          chap.classList.remove("hide");
          chap.style.left = phot.offsetLeft + phot_width/2 - chap.offsetWidth/2 + "px";
          chap.classList.add("hide");
          chap.style.top = "33px";
          stache.style.width = (phot_width/640)*220+"px";
          stache.style.height = (phot_width/640)*130+"px";
          stache.classList.remove("hide");
          stache.style.left = phot.offsetLeft + phot_width/2 - stache.offsetWidth/2 + "px";
          stache.style.top = 18 + phot.offsetHeight/2 - stache.offsetHeight/2 + "px";
          stache.classList.add("hide");
	}
	 else
	{
      navigator.mediaDevices.getUserMedia({ video: true, audio: true }).then(function(stream) {
        var video = document.querySelector('video');
        video.srcObject = stream;
        video.onloadedmetadata = function(e){
        	video.play();
          var chap = document.getElementById("chap");
          video_width = video.offsetWidth;
          chap.style.width = (video_width/640)*200+"px";
          chap.style.height = (video_width/640)*170+"px";
          chap.classList.remove("hide");
          chap.style.left = video.offsetLeft + video_width/2 - chap.offsetWidth/2 + "px";
          chap.classList.add("hide");
          chap.style.top = "15px";
          stache.style.width = (video_width/640)*220+"px";
          stache.style.height = (video_width/640)*130+"px";
          stache.classList.remove("hide");
          stache.style.left = video.offsetLeft + video_width/2 - stache.offsetWidth/2 + "px";
          stache.style.top = video.offsetHeight/2 - stache.offsetHeight/2 + "px";
          stache.classList.add("hide");
		  cache_div.classList.remove("hide");
        };
      }).catch(function(e) {
        document.querySelector('form').classList.remove('hide');
		video.classList.add("hide");
      });
	}
  }
