<?php
	echo "aaaaa";
print_r($_FILES["userfile"]);
if (exif_imagetype($_FILES["userfile"]["tmp_name"]) == 2 || exif_imagetype($_FILES["userfile"]["tmp_name"]) == 3)
{
	echo "aaaaa";
	if (exif_imagetype($_FILES["userfile"]["tmp_name"]) == 2)
		$img = imagecreatefromjpeg($_FILES["userfile"]["tmp_name"]);
	else if (exif_imagetype($_FILES["userfile"]["tmp_name"]) == 3)
		$img = imagecreatefrompng($_FILES["userfile"]["tmp_name"]);
	if (imagesy($img) > 60)
	{
		$src = imagecreatetruecolor(imagesx($img), imagesy($img));
		imagecolortransparent($src, imagecolorallocatealpha($src, 0, 0, 0, 127));
		imagealphablending($src, false);
		imagesavealpha($src, true);
		imagecopyresampled($src, $img, 0, 0, 0, 0, imagesx($img), imagesy($img), imagesx($img), imagesy($img));
		unlink("../images/tmp.png");
		imagepng($src, "../images/tmp.png");
		header("Cache-Control: no-cache, must-revalidate");
		header("Location: /montage/montage.php?photo=1");
	}
	else
		header("Location: /montage/montage.php?error=height");
}
else if ($_FILES["userfile"]["error"] == 2)
	header("Location: /montage/montage.php?error=size");
else
	header("Location: /montage/montage.php?error=type");


?>
