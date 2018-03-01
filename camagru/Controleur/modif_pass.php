<?PHP

$pseudo = htmlspecialchars($_GET["log"]);
$cle = htmlspecialchars($_GET["cle"]);

Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/check_cle.php');

if ($user)
	include_once ($_SERVER['DOCUMENT_ROOT'].'/Vue/modif_pass.php');
else
	header("Location: /index.php?error=auth");
?>
