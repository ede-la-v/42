<?PHP

$pseudo = htmlspecialchars($_GET["log"]);
$cle = htmlspecialchars($_GET["cle"]);

Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/activ_user.php');
?>
