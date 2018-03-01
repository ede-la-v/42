<?php
session_start();
$source = base64_decode(str_replace("=", "", str_replace("data:image/png;base64,", "", $_POST["img"])));

$destination = imagecreatefromstring($source);
if (!$_POST["type"] == 0)
{
	if ($_POST["type"] == 2)
		$source = imagecreatefrompng("http://www.wallquotes.com/sites/default/files/arts0508.png");
	else if ($_POST["type"] == 1)
		$source = imagecreatefrompng("http://ekladata.com/-6PR_q9lfWwRV4FymruNhlQ1sUE.png");

	if ($_POST["type"] == 1)
	{
	  $percent_width = 200/640;
	$percent_height = 170/200;
	$position_width = imagesx($destination)/2 - imagesx($destination)*(100/640);
	$position_height = 15;
	}
	else
	  {
	  $percent_width = 220/640;
	$percent_height = 130/220;
	$position_width = imagesx($destination)/2 - imagesx($destination)*(110/640);
	$position_height = imagesy($destination)/2 - imagesy($destination)*(65/480);
	}

	$src = imagecreatetruecolor(imagesx($destination)*($percent_width), imagesx($destination)*($percent_width)*($percent_height));
	imagecolortransparent($src, imagecolorallocatealpha($src, 0, 0, 0, 127));
	imagealphablending($src, false);
	imagesavealpha($src, true);
	imagecopyresampled($src, $source, 0, 0, 0, 0, imagesx($destination)*($percent_width), imagesx($destination)*($percent_width)*($percent_height), imagesx($source), imagesy($source));
	$src2 = imagecreatetruecolor(imagesx($destination), imagesy($destination));
	imagecolortransparent($src2, imagecolorallocatealpha($src2, 0, 0, 0, 127));
	imagealphablending($src2, false);
	imagesavealpha($src2, true);
	imagecopyresampled($src2, $destination, 0, 0, 0, 0, imagesx($destination), imagesy($destination), imagesx($destination), imagesy($destination));


	imagecopy($src2, $src, $position_width, $position_height, 0, 0, imagesx($src), imagesy($src));
}
  Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/put_img.php');
  Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/last_img.php');

  $num = $resultat["id"];
 
imagepng($src2, "../images/".$num.".png");
echo $num;

?>
